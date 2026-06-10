local ghostty = require "lib.ghostty"

local pty = require "pty"
local input = require "input"
local utf8 = require "utf8"

local lgbt = {}

local function lerp(a, b, t)
  local v = a + (b - a) * t
  if eps and math.abs(v - b) < 0.1 then return b end
  return v
end

function love.load()
  love.keyboard.setKeyRepeat(true)
  love.graphics.setDefaultFilter("nearest", "nearest")
  lgbt.font = love.graphics.newFont("departure.otf", 11)

  local line_height, width = lgbt.font:getHeight(), lgbt.font:getWidth("m")

  lgbt.rows = math.floor(love.graphics.getHeight() / line_height)
  lgbt.cols = math.floor(love.graphics.getWidth() / width)
  lgbt.cell_w = width
  lgbt.cell_h = line_height

  lgbt.terminal = ghostty.GhosttyTerminal:new { rows = lgbt.rows, cols = lgbt.cols, max_scrollback = 1000 }

  -- TODO: wait for ready
  -- TODO: handle infant mortality :(
  lgbt.pty = pty:spawn {rows = lgbt.rows, cols = lgbt.cols, width = love.graphics.getWidth(), height = love.graphics.getHeight() }

  lgbt.render_state, lgbt.row_iterator, lgbt.row_cells = ghostty:new_render_state_ptrs()

  lgbt.key_encoder = ghostty.GhosttyKeyEncoder:new()
  lgbt.key_events = {}

  lgbt.terminal:set_color_theme({
    background = { r = 0x1A, g = 0x1C, b = 0x2C },
    foreground = { r = 0xF4, g = 0xF4, b = 0xF4 },
    cursor     = { r = 0x94, g = 0xB0, b = 0xC2 },
    
    colors = {
      { r = 0x1A, g = 0x1C, b = 0x2C },
      { r = 0xB1, g = 0x3E, b = 0x53 },
      { r = 0x25, g = 0x71, b = 0x79 },
      { r = 0xFF, g = 0xCD, b = 0x75 },
      { r = 0x29, g = 0x36, b = 0x6F },
      { r = 0x5D, g = 0x27, b = 0x5D },
      { r = 0x41, g = 0xA6, b = 0xF6 },
      { r = 0x56, g = 0x6C, b = 0x86 },
      { r = 0x33, g = 0x3C, b = 0x57 },
      { r = 0xEF, g = 0x7D, b = 0x57 },
      { r = 0x38, g = 0xB7, b = 0x64 },
      { r = 0xA7, g = 0xF0, b = 0x70 },
      { r = 0x3B, g = 0x5D, b = 0xC9 },
      { r = 0x73, g = 0xEF, b = 0xF7 },
      { r = 0x94, g = 0xB0, b = 0xC2 },
      { r = 0xF4, g = 0xF4, b = 0xF4 },
    }
  })

  lgbt.cursor = { x = 0, y = 0, opacity = 0 }
end

function love.update(dt)
  local t = 1 - math.exp(-10 * dt)

  pty:read(function(buf, size) lgbt.terminal:write(buf, size) end)

  ghostty:render_state_update(lgbt.render_state[0], lgbt.terminal.handle)

  lgbt.key_encoder:setopt_from_terminal(lgbt.terminal.handle)

  for _, key_event in ipairs(lgbt.key_events) do
    if not key_event:is_release() then
      local text = input:drain()
      key_event:set_utf8(text, #text)
    end

    local data = lgbt.key_encoder:encode(key_event.handle)
    pty:write(data)
  end

  lgbt.key_events = {}

  local cursor = ghostty:get_cursor(lgbt.render_state)
  lgbt.cursor.opacity = lerp(lgbt.cursor.opacity, cursor and 128 or 0, t)
  if cursor then
    lgbt.cursor.x = lerp(lgbt.cursor.x, cursor.x, t)
    lgbt.cursor.y = lerp(lgbt.cursor.y, cursor.y, t)
  end
end

function love.draw()
  love.graphics.setFont(lgbt.font)

  local colors_ptr = ghostty:render_state_colors_get(lgbt.render_state[0])
  local colors = colors_ptr[0]
  local bg = colors.background
  love.graphics.clear(love.math.colorFromBytes(bg.r, bg.g, bg.b, 255))

  for y in ghostty:render_state_row_iterator(lgbt.render_state, lgbt.row_iterator) do
    for x, text, style in ghostty:render_state_cells_iterator(lgbt.row_iterator, lgbt.row_cells) do
      if style then
        local fg = ghostty:resolve_color(style[0].fg_color, colors)

        love.graphics.setColor(love.math.colorFromBytes(fg.r, fg.g, fg.b, 255))

        love.graphics.print(text, x * lgbt.cell_w, y * lgbt.cell_h)
      end
    end
  end

  local fg = colors.foreground
  if colors.cursor_has_value ~= 0 then fg = colors.cursor end

  love.graphics.setColor(love.math.colorFromBytes(fg.r, fg.g, fg.b, lgbt.cursor.opacity))
  love.graphics.rectangle("fill", lgbt.cursor.x * lgbt.cell_w, lgbt.cursor.y * lgbt.cell_h, lgbt.cell_w, lgbt.cell_h)

  ghostty:clean_state(lgbt.render_state)
end

function love.keypressed(_, scancode, isrepeat)
  -- crude and wrong clipboard manager
  if scancode == "v" and love.keyboard.isDown "lgui" then
    input:push_text(love.system.getClipboardText())
  end

  local ok, key = ghostty:get_ghostty_key(input:get_code(scancode))
  if not ok then return end

  local mods = input:get_mods()
  local key_event = ghostty.GhosttyKeyEvent:press(key, mods, isrepeat)

  table.insert(lgbt.key_events, key_event)
end

function love.keyreleased(_, scancode)
  local ok, key = ghostty:get_ghostty_key(input:get_code(scancode))
  if not ok then return end

  local key_event = ghostty.GhosttyKeyEvent:release(key)

  table.insert(lgbt.key_events, key_event)
end

function love.textinput(text)
  input:push_text(text)
end

function love.wheelmoved(x, y)
  lgbt.terminal:scroll_viewport(-y)
end
