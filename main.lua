local ghostty = require "lib.ghostty"
local tela_preta = {}

local SIZE = 24

function love.load()
  love.graphics.setDefaultFilter("nearest", "nearest")
  tela_preta.font = love.graphics.newFont("departure.otf", 22)

  tela_preta.rows = love.graphics.getHeight() / SIZE
  tela_preta.cols = love.graphics.getWidth() / SIZE

  tela_preta.terminal = ghostty:new_terminal({ rows = tela_preta.rows, cols = tela_preta.cols, max_scrollback = 1000 })
end

function love.update(dt)
end

function love.draw()
  love.graphics.setFont(tela_preta.font)
  love.graphics.print("hello world")
end
