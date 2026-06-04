local ffi = require "ffi"

-- ffi.cdef [[
--   typedef struct GhosttyTerminalImpl* GhosttyTerminal;
--
--   typedef struct {
--     /** Terminal width in cells. Must be greater than zero. */
--     uint16_t cols;
--
--     /** terminal height in cells. must be greater than zero. */
--     uint16_t rows;
--
--     /** maximum number of lines to keep in scrollback history. */
--     size_t max_scrollback;
--   } ghosttyterminaloptions;
--
--   // todo: (brennim): use ghostty_result
--   int ghostty_terminal_new(const void* allocator, // todo: (brennim) should we use an explicit allocator
--                                    ghosttyterminal* terminal,
--                                    ghosttyterminaloptions options);
-- ]]

ffi.cdef(io.open("lib/ghostty-vt.h"):read("*a"))

local C = ffi.load("ghostty-vt")

local ghostty = { }

function ghostty:new_terminal(opts)
  local options = ffi.new("GhosttyTerminalOptions", opts)
  local terminal = ffi.new("GhosttyTerminal[1]")
  local result = C.ghostty_terminal_new(nil, terminal, options)
  assert(result == "GHOSTTY_SUCCESS", "ghostty_terminal_new = " .. tostring(result))
  ffi.gc(terminal, C.ghostty_terminal_free)
  return terminal
end

return ghostty
