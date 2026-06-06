local ffi = require "ffi"

ffi.cdef(io.open("lib/ghostty-vt.h"):read("*a"))

local C = ffi.load "ghostty-vt"

local ghostty = { }

function ghostty:new_terminal(opts)
  local options = ffi.new("GhosttyTerminalOptions", opts)
  local terminal = ffi.gc(ffi.new "GhosttyTerminal[1]", function(t) C.ghostty_terminal_free(t[0]) end)
  local result = C.ghostty_terminal_new(nil, terminal, options)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_terminal_new = " .. tostring(result))
  return terminal
end

function ghostty:write_terminal(terminal, buffer, size)
  C.ghostty_terminal_vt_write(terminal, buffer, size)
end

-- will be removed
function ghostty:new_formatter(terminal)
  local fmt = ffi.new "GhosttyFormatterTerminalOptions"
  fmt.size = ffi.sizeof(fmt)
  fmt.emit = ffi.C.GHOSTTY_FORMATTER_FORMAT_PLAIN
  fmt.trim = true

  local formatter = ffi.new "GhosttyFormatter[1]"
  local result = C.ghostty_formatter_terminal_new(nil, formatter, terminal, fmt)

  assert(result == "GHOSTTY_SUCCESS", "ghostty_formatter_terminal_new = " .. tostring(result))
  -- ffi.gc(formatter[0], C.ghostty_formatter_free)

  return formatter[0]
end

-- will be removed
function ghostty:format_alloc(formatter)
  local buf = ffi.new "uint8_t*[1]"
  local len = ffi.new "size_t[1]"
  local result = C.ghostty_formatter_format_alloc(formatter, NULL, buf, len)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_formatter_format_alloc = " .. tostring(result))
  local str = ffi.string(buf[0], len[0])
  C.ghostty_free(nil, buf[0], len[0]) -- this might be wrong
  return str
end

return ghostty
