local ghostty = require "lib.ghostty"

local pty = require "pty"

local tela_preta = {}

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")
  tela_preta.font = love.graphics.newFont("departure.otf", 22)

  local line_height, width = tela_preta.font:getHeight(), tela_preta.font:getWidth("m")

  tela_preta.rows = math.floor(love.graphics.getHeight() / line_height)
  tela_preta.cols = math.floor(love.graphics.getWidth() / width)

  tela_preta.terminal_ptr = ghostty:new_terminal { rows = tela_preta.rows, cols = tela_preta.cols, max_scrollback = 1000 }
  tela_preta.terminal = tela_preta.terminal_ptr[0]

  tela_preta.pty = pty:spawn {rows = tela_preta.rows, cols = tela_preta.cols, width = love.graphics.getWidth(), height = love.graphics.getHeight() }

  -- tela_preta.encoder = ghostty:new_encoder()
  -- tela_preta.event = ghostty:new_event()
end

function love.update(dt)
  pty:read(function(buf, size) ghostty:write_terminal(tela_preta.terminal, buf, size) end)
end

function love.draw()
  love.graphics.setFont(tela_preta.font)

  local formatter = ghostty:new_formatter(tela_preta.terminal)
  local buffer = ghostty:format_alloc(formatter)

  love.graphics.print(buffer)
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
