local ffi = require "ffi"

ffi.cdef(io.open("lib/ghostty-vt.h"):read("*a"))

local C = ffi.load "ghostty-vt"

local ghostty = {
  GhosttyTerminal = {}
}

local ghostty_terminal_wrapper = ffi.metatype("struct { GhosttyTerminal handle; }", { 
  __index = ghostty.GhosttyTerminal,
  __gc = function(self) C.ghostty_terminal_free(self.handle) end,
})

function ghostty.GhosttyTerminal:write(buffer, size)
  C.ghostty_terminal_vt_write(self.handle, buffer, size)
end

function ghostty.GhosttyTerminal:new(opts)
  local options = ffi.new("GhosttyTerminalOptions", opts)
  local terminal_ptr = ffi.new "GhosttyTerminal[1]"
  local result = C.ghostty_terminal_new(nil, terminal_ptr, options)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_terminal_new = " .. tostring(result))

  local terminal = ghostty_terminal_wrapper()
  terminal.handle = terminal_ptr[0]
  return terminal
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
  local colors = ffi.new "GhosttyRenderStateColors[1]" -- FIXME: should this have a GC?
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
      return x + 1, ""
    end

    local codepoints = ffi.new "uint32_t[16]"
    C.ghostty_render_state_row_cells_get(cells[0], C.GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_BUF, codepoints)
    local text = ffi.string(codepoints, 1) 

    
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

return ghostty
