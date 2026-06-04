local ffi = require "ffi"

ffi.cdef [[
  struct winsize {
    unsigned short ws_row;
    unsigned short ws_col;
    unsigned short ws_xpixel;
    unsigned short ws_ypixel;
  };

  int forkpty(int *amaster, char *name, struct termios *termp, struct winsize *winp);
  int fcntl(int fd, int cmd, ...);

  int read(int fd, void *buf, size_t count);
]]

local util = ffi.load "util"

local pty = { fd = 0 }

local F_SETFL = 4
local O_NONBLOCK = 0x4

-- return master fd and child pid
function pty:spawn(options)
  local master = ffi.new "int[1]"

  local winsize = ffi.new("struct winsize", { options.rows, options.cols })

  local pid = util.forkpty(master, nil, nil, ws)
  assert(pid >= 0, "forkpty failed")

  if pid == 0 then -- CHILD
    local argv = ffi.new("const char*[3]", {
        ffi.cast("const char*", ffi.new("char[?]", 5, "bash")),
        nil
    })

    ffi.C.execvp("/bin/bash", argv)
    os.exit(1)  -- only reached if exec fails
  end

  print("child pid", pid)

  self.fd = master[0]
  ffi.C.fcntl(self.fd, F_SETFL, O_NONBLOCK)

  return pid
end

-- write to master fd
function pty:write(data)
  -- TODO: handle partial writes and EINTR on nonblocking master fd
  -- https://github.com/ghostty-org/ghostling/commit/b7ac06180acf41a0142412fd9e37d6a1c553841e

  util.write(self.fd, data, #data)
end

-- drain master fd, returns result OK | EOF | ERR
function pty:read(callback)
  local buf = ffi.new("char[4096]")
  while true do
    local n = ffi.C.read(self.fd, buf, 4096)
    if n <= 0 then break end

    callback(buf, n)
  end
end

return pty
