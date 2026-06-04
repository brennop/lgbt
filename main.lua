local ghostty = require "lib.ghostty"

local pty = require "lpty"

local tela_preta = {}

local SIZE = 24

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")
  tela_preta.font = love.graphics.newFont("departure.otf", 22)

  tela_preta.rows = love.graphics.getHeight() / SIZE
  tela_preta.cols = love.graphics.getWidth() / SIZE

  tela_preta.terminal = ghostty:new_terminal { rows = tela_preta.rows, cols = tela_preta.cols, max_scrollback = 1000 }

  tela_preta.pty = pty:spawn {rows = tela_preta.rows, cols = tela_preta.cols }

  -- tela_preta.encoder = ghostty:new_encoder()
  -- tela_preta.event = ghostty:new_event()
end

function love.update(dt)
  pty:read(function(buf, size) ghostty:write_terminal(tela_preta.terminal, buf, size) end)

end

function love.draw()
  love.graphics.setFont(tela_preta.font)

  -- TODO: copy: https://github.com/ghostty-org/ghostling/blob/1e6dfa40575b335988c989cb0613b309dc61b415/main.c#L185 
end
