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

-- will be removed
function ghostty:new_formatter(terminal)
  local fmt = ffi.new "GhosttyFormatterTerminalOptions"
  fmt.size = ffi.sizeof(fmt)
  fmt.emit = ffi.C.GHOSTTY_FORMATTER_FORMAT_PLAIN
  fmt.trim = true

  local formatter = ffi.gc(ffi.new "GhosttyFormatter[1]", function(f) C.ghostty_formatter_free(f[0]) end)
  local result = C.ghostty_formatter_terminal_new(nil, formatter, terminal, fmt)

  assert(result == "GHOSTTY_SUCCESS", "ghostty_formatter_terminal_new = " .. tostring(result))

  return formatter
end

-- will be removed
function ghostty:format_alloc(formatter)
  local buf = ffi.new "uint8_t*[1]"
  local len = ffi.new "size_t[1]"
  local result = C.ghostty_formatter_format_alloc(formatter, NULL, buf, len)
  local str = ffi.string(buf[0], len[0])
  C.ghostty_free(nil, buf[0], len[0]) -- this might be wrong
  return str
end

function ghostty:new_render_state_ptrs()
  local render_state = ffi.gc(ffi.new "GhosttyRenderState[1]", function(ptr) C.ghostty_render_state_free(ptr[0]) end)
  assert(C.ghostty_render_state_new(nil, render_state) == "GHOSTTY_SUCCESS")
  local row_iterator = ffi.gc(ffi.new "GhosttyRenderStateRowIterator[1]", function(ptr) C.ghostty_render_state_row_iterator_free(ptr[0]) end)
  assert(C.ghostty_render_state_row_iterator_new(nil, row_iterator) == "GHOSTTY_SUCCESS")
  local row_cells = ffi.gc(ffi.new "GhosttyRenderStateRowCells[1]", function(ptr) C.ghostty_render_state_row_cells_free(ptr[0]) end)
  assert(C.ghostty_render_state_row_cells_new(nil, row_cells) == "GHOSTTY_SUCCESS")

  return { render_state = render_state, row_iterator = row_iterator, row_cells = row_cells }
end

function ghostty:render_state_update(render_state_ptr, terminal_ptr)
  C.ghostty_render_state_update(render_state_ptr[0], terminal_ptr[0])
end

return ghostty
