local ffi = require "ffi"

ffi.cdef(io.open("lib/ghostty-vt.h"):read("*a"))

local C = ffi.load "ghostty-vt"

local ghostty = { }

function ghostty:new_terminal(opts)
  local options = ffi.new("GhosttyTerminalOptions", opts)
  local terminal = ffi.new("GhosttyTerminal[1]")
  local result = C.ghostty_terminal_new(nil, terminal, options)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_terminal_new = " .. tostring(result))
  ffi.gc(terminal[0], C.ghostty_terminal_free)
  return terminal[0]
end

function ghostty:write_terminal(terminal, buffer, size)
  C.ghostty_terminal_vt_write(terminal, buffer, size)
end

return ghostty
