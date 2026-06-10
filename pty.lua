local posix  = require "posix"
local unistd = require "posix.unistd"
local stdio  = require "posix.stdio"
local stdlib = require "posix.stdlib"
local fcntl  = require "posix.fcntl"
local termio = require "posix.termio"

local pty = {}

-- FIXME: isn't it missing login_tty?
function pty:spawn(opts)
  local master, slave, slave_name = posix.openpty()

  local ok, errmsg, errnum = termio.tcsetwinsize(master, {ws_row=opts.rows, ws_col=opts.cols, ws_xpixel=opts.width, ws_ypixel=opts.height})

  local pid = unistd.fork()

  if pid == 0 then
    -- child
    unistd.close(master)
    unistd.setpid("s", 0)  -- setsid()

    -- re-open slave by name so kernel attaches it as controlling terminal
    -- i guess this mirrors login_tty from forkpty
    local ctty = fcntl.open(slave_name, fcntl.O_RDWR)
    unistd.close(slave)

    -- this is also from login_tty ?
    unistd.dup2(ctty, 0)
    unistd.dup2(ctty, 1)
    unistd.dup2(ctty, 2)
    if ctty > 2 then unistd.close(ctty) end

    stdlib.setenv("TERM", "xterm", true)
    unistd.execp("sh", { })
    os.exit(1) -- deu ruim
  else
    -- parent
    unistd.close(slave)

    local flags = fcntl.fcntl(master, fcntl.F_GETFL)
    fcntl.fcntl(master, fcntl.F_SETFL, bit.bor(flags, fcntl.O_NONBLOCK))

    self.master = master
    return pid
  end
end

function pty:write(data)
  unistd.write(self.master, data)
end

function pty:read(callback)
  while true do
    local output, error, errnum = unistd.read(self.master, 4096)
    if not output or #output == 0 then break end
    callback(output, #output)
  end
end

return pty
