local ffi = require "ffi"
local utf8 = require "utf8"

ffi.cdef(io.open("lib/ghostty-vt.h"):read("*a"))

local C = ffi.load "ghostty-vt"

local ghostty = {
  GhosttyTerminal = {},
  GhosttyKeyEncoder = {},
  GhosttyKeyEvent = {},
}

local ghostty_terminal_t = ffi.metatype("struct { GhosttyTerminal handle; }", { 
  __index = ghostty.GhosttyTerminal,
  __gc = function(self) C.ghostty_terminal_free(self.handle) end,
})

local ghostty_key_encoder_t = ffi.metatype("struct { GhosttyKeyEncoder handle; }", {
  __index = ghostty.GhosttyKeyEncoder,
  __gc = function(self) C.ghostty_key_encoder_free(self.handle) end,
})

local ghostty_key_event_t = ffi.metatype("struct { GhosttyKeyEvent handle; }", {
  __index = ghostty.GhosttyKeyEvent,
  __gc = function(self) C.ghostty_key_event_free(self.handle) end,
})

function ghostty.GhosttyTerminal:write(buffer, size)
  C.ghostty_terminal_vt_write(self.handle, buffer, size)
end

function ghostty.GhosttyTerminal:new(opts)
  local options = ffi.new("GhosttyTerminalOptions", opts)
  local terminal_ptr = ffi.new "GhosttyTerminal[1]"
  local result = C.ghostty_terminal_new(nil, terminal_ptr, options)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_terminal_new = " .. tostring(result))

  local terminal = ghostty_terminal_t()
  terminal.handle = terminal_ptr[0]
  return terminal
end

function ghostty.GhosttyKeyEncoder:new()
  local key_encoder_ptr = ffi.new "GhosttyKeyEncoder[1]"
  local result = C.ghostty_key_encoder_new(nil, key_encoder_ptr)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_key_encoder_new = " .. tostring(result))

  local key_encoder = ghostty_key_encoder_t()
  key_encoder.handle = key_encoder_ptr[0]
  return key_encoder
end

-- Sync encoder options from the terminal so mode changes are honoured
function ghostty.GhosttyKeyEncoder:setopt_from_terminal(terminal)
  C.ghostty_key_encoder_setopt_from_terminal(self.handle, terminal)
end

function ghostty.GhosttyKeyEvent.new()
  local key_event_ptr = ffi.new "GhosttyKeyEvent[1]"
  local result = C.ghostty_key_event_new(nil, key_event_ptr)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_key_event_new = " .. tostring(result))

  local key_event = ghostty_key_event_t()
  key_event.handle = key_event_ptr[0]
  return key_event
end

function ghostty.GhosttyKeyEvent:press(key, mods, is_repeat)
  local key_event = ghostty.GhosttyKeyEvent.new()

  C.ghostty_key_event_set_key(key_event.handle, key)
  C.ghostty_key_event_set_mods(key_event.handle, mods)

  if is_repeat then
    C.ghostty_key_event_set_action(key_event.handle, C.GHOSTTY_KEY_ACTION_REPEAT)
  else
    C.ghostty_key_event_set_action(key_event.handle, C.GHOSTTY_KEY_ACTION_PRESS)
  end

  return key_event
end

function ghostty.GhosttyKeyEvent:release(key)
  local key_event = ghostty.GhosttyKeyEvent.new()

  C.ghostty_key_event_set_key(key_event.handle, key)
  C.ghostty_key_event_set_mods(key_event.handle, 0)
  C.ghostty_key_event_set_action(key_event.handle, C.GHOSTTY_KEY_ACTION_RELEASE)

  return key_event
end

function ghostty.GhosttyKeyEvent:is_release()
  return C.ghostty_key_event_get_action(self.handle) == C.GHOSTTY_KEY_ACTION_RELEASE
end

function ghostty.GhosttyKeyEvent:set_key(key)
  C.ghostty_key_event_set_key(self.handle, key)
end

function ghostty.GhosttyKeyEvent:set_action(action)
  C.ghostty_key_event_set_action(self.handle, C[action])
end

function ghostty.GhosttyKeyEvent:set_mods(mods)
  C.ghostty_key_event_set_mods(self.handle, mods)
end

function ghostty.GhosttyKeyEvent:set_utf8(text, len)
  C.ghostty_key_event_set_utf8(self.handle, text, len)
end


function ghostty:new_render_state_ptrs()
  local render_state = ffi.gc(ffi.new "GhosttyRenderState[1]", function(ptr) C.ghostty_render_state_free(ptr[0]) end)
  assert(C.ghostty_render_state_new(nil, render_state) == "GHOSTTY_SUCCESS")
  local row_iterator = ffi.gc(ffi.new "GhosttyRenderStateRowIterator[1]", function(ptr) C.ghostty_render_state_row_iterator_free(ptr[0]) end)
  assert(C.ghostty_render_state_row_iterator_new(nil, row_iterator) == "GHOSTTY_SUCCESS")
  local row_cells = ffi.gc(ffi.new "GhosttyRenderStateRowCells[1]", function(ptr) C.ghostty_render_state_row_cells_free(ptr[0]) end)
  assert(C.ghostty_render_state_row_cells_new(nil, row_cells) == "GHOSTTY_SUCCESS")

  return render_state, row_iterator, row_cells
end

function ghostty:render_state_update(render_state, terminal)
  C.ghostty_render_state_update(render_state, terminal)
end

function ghostty:render_state_colors_get(render_state)
  local colors = ffi.new "GhosttyRenderStateColors[1]"
  colors[0].size = ffi.sizeof(colors[0])

  assert(C.ghostty_render_state_colors_get(render_state, colors) == "GHOSTTY_SUCCESS")
  
  return colors
end

function ghostty:render_state_row_iterator(render_state, row_iter)
  -- populates the row iterator with current render state
  assert(C.ghostty_render_state_get(render_state[0], C.GHOSTTY_RENDER_STATE_DATA_ROW_ITERATOR, row_iter) == "GHOSTTY_SUCCESS")

  return function(_, y)
    if last ~= -1 then
      local clean = ffi.new "uint8_t[1]"
      clean[0] = false
      C.ghostty_render_state_row_set(row_iter[0], C.GHOSTTY_RENDER_STATE_ROW_OPTION_DIRTY, clean)
    end

    if C.ghostty_render_state_row_iterator_next(row_iter[0]) == 0 then return nil end

    return y + 1
  end, nil, -1 -- starting y
end

function ghostty:render_state_cells_iterator(row_iter, cells)
  assert(C.ghostty_render_state_row_get(row_iter[0], C.GHOSTTY_RENDER_STATE_ROW_DATA_CELLS, cells) == "GHOSTTY_SUCCESS")

  return function(_, x)
    if C.ghostty_render_state_row_cells_next(cells[0]) == 0 then 
      return nil 
    end

    local grapheme_len = ffi.new "uint32_t[1]"
    C.ghostty_render_state_row_cells_get(cells[0], C.GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_LEN, grapheme_len)

    if grapheme_len[0] == 0 then
      return x + 1
    end

    local codepoints = ffi.new "uint32_t[16]"
    local len = grapheme_len[0] < 16 and grapheme_len[0] or 16
    C.ghostty_render_state_row_cells_get(cells[0], C.GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_BUF, codepoints)

    -- this is ugly but apparently the only way to copy a c array into a table
    local codepoints_tbl = {}
    for i = 0, len do 
      codepoints_tbl[i + 1] = codepoints[i]
    end
    local text = utf8.char(unpack(codepoints_tbl))
    
    local style = ffi.new "GhosttyStyle[1]" 
    style[0].size = ffi.sizeof(style[0])
    C.ghostty_render_state_row_cells_get(cells[0], C.GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_STYLE, style)

    return x + 1, text, style
  end, nil, -1 -- starting x
end

function ghostty:resolve_color(color, colors)
  if color.tag == C.GHOSTTY_STYLE_COLOR_RGB then
    return color.value.rgb
  elseif color.tag == C.GHOSTTY_STYLE_COLOR_PALETTE then
    return colors.palette[color.value.palette]
  end

  return { r = 255, g = 255, b = 255 }
end


-- TODO: convert all these render_state_gets to a metamethod
function ghostty:get_cursor(render_state)
  local cursor_visible = ffi.new "bool[1]"
  cursor_visible[0] = false
  C.ghostty_render_state_get(render_state[0], C.GHOSTTY_RENDER_STATE_DATA_CURSOR_VISIBLE, cursor_visible)

  local cursor_in_viewport = ffi.new "bool[1]"
  cursor_in_viewport[0] = false
  C.ghostty_render_state_get(render_state[0], C.GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_HAS_VALUE, cursor_in_viewport)

  if cursor_visible[0] and cursor_in_viewport[0] then
    local x, y = ffi.new "uint16_t[1]", ffi.new "uint16_t[1]"
    C.ghostty_render_state_get(render_state[0], C.GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_X, x)
    C.ghostty_render_state_get(render_state[0], C.GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_Y, y)

    return { x = x[0], y = y[0] }
  end
end

function ghostty:clean_state(render_state)
  local clean_state = ffi.new "GhosttyRenderStateDirty[1]"
  clean_state[0] = C.GHOSTTY_RENDER_STATE_DIRTY_FALSE;

  C.ghostty_render_state_set(render_state[0], C.GHOSTTY_RENDER_STATE_OPTION_DIRTY, clean_state)
end

function ghostty:get_ghostty_key(key)
  return pcall(getmetatable(C).__index, C, "GHOSTTY_KEY_" .. key)
end

function ghostty.GhosttyKeyEncoder:encode(event)
  local buffer = ffi.new "char[128]"
  local sizeof = ffi.sizeof(buffer) -- FIX: won't this be static??
  local written = ffi.new "size_t[1]"
  local result = C.ghostty_key_encoder_encode(self.handle, event, buffer, sizeof, written)
  assert(result == "GHOSTTY_SUCCESS")

  local data = ffi.string(buffer, written[0]) 
  return data
end

return ghostty
