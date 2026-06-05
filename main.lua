local ghostty = require "lib.ghostty"

local pty = require "pty"

local tela_preta = {}

local SIZE = 12

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")
  tela_preta.font = love.graphics.newFont("departure.otf", 22)

  tela_preta.rows = math.floor(love.graphics.getHeight() / SIZE)
  tela_preta.cols = math.floor(love.graphics.getWidth() / SIZE)

  tela_preta.terminal = ghostty:new_terminal { rows = tela_preta.rows, cols = tela_preta.cols, max_scrollback = 1000 }

  tela_preta.pty = pty:spawn {rows = tela_preta.rows, cols = tela_preta.cols, width = tela_preta.cols * SIZE, height = tela_preta.rows * SIZE }

  -- tela_preta.encoder = ghostty:new_encoder()
  -- tela_preta.event = ghostty:new_event()
end

function love.update(dt)
  pty:read(function(buf, size) 
    ghostty:write_terminal(tela_preta.terminal, buf, size) 
  end)
end

function love.draw()
  love.graphics.setFont(tela_preta.font)

  local formatter = ghostty:new_formatter(tela_preta.terminal)
  local buffer = ghostty:format_alloc(formatter)

  love.graphics.print(buffer)
end
