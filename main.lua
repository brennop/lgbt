local ghostty = require "lib.ghostty"

local pty = require "pty"

local lgbt = {}

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")
  lgbt.font = love.graphics.newFont("departure.otf", 22)

  local line_height, width = lgbt.font:getHeight(), lgbt.font:getWidth("m")

  lgbt.rows = math.floor(love.graphics.getHeight() / line_height)
  lgbt.cols = math.floor(love.graphics.getWidth() / width)
  lgbt.cell_w = width
  lgbt.cell_h = line_height

  lgbt.terminal = ghostty.GhosttyTerminal:new { rows = lgbt.rows, cols = lgbt.cols, max_scrollback = 1000 }

  lgbt.pty = pty:spawn {rows = lgbt.rows, cols = lgbt.cols, width = love.graphics.getWidth(), height = love.graphics.getHeight() }

  lgbt.render_state, lgbt.row_iterator, lgbt.row_cells = ghostty:new_render_state_ptrs()

  -- lgbt.encoder = ghostty:new_encoder()
  -- lgbt.event = ghostty:new_event()
end

function love.update(dt)
  pty:read(function(buf, size) lgbt.terminal:write(buf, size) end)

  ghostty:render_state_update(lgbt.render_state[0], lgbt.terminal.handle)
end

function love.draw()
  love.graphics.setFont(lgbt.font)

  local colors_ptr = ghostty:render_state_colors_get(lgbt.render_state[0])
  local colors = colors_ptr[0]
  local bg = colors.background
  love.graphics.setBackgroundColor(love.math.colorFromBytes(bg.r, bg.g, bg.b, 255))

  for y in ghostty:render_state_row_iterator(lgbt.render_state, lgbt.row_iterator) do
    for x, text, style in ghostty:render_state_cells_iterator(lgbt.row_iterator, lgbt.row_cells) do
      if style then
        local fg = ghostty:resolve_color(style[0].fg_color, colors)
        love.graphics.setColor(love.math.colorFromBytes(fg.r, fg.g, fg.b, 255))

        love.graphics.print(text, x * lgbt.cell_w, y * lgbt.cell_h)
      end
    end
  end

  local cursor = ghostty:get_cursor(lgbt.render_state)
  if cursor then
    local fg = colors.foreground
    if colors.cursor_has_value ~= 0 then fg = colors.cursor end
    love.graphics.setColor(love.math.colorFromBytes(fg.r, fg.g, fg.b, 128))

    love.graphics.rectangle("fill", cursor.x * lgbt.cell_w, cursor.y * lgbt.cell_h, lgbt.cell_w, lgbt.cell_h)
  end

  ghostty:clean_state(lgbt.render_state)
end

local codes = {
  ["return"] = "\r",
  ["backspace"] = "\127"
}

function love.keypressed(key, scancode, isrepeat)
  local code = codes[scancode]
  if code then pty:write(code) end
end

function love.textinput(text)
  pty:write(text)
end
