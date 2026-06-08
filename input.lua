local input = {
  queue = "",
  text = ""
}

-- maps love's KeyConstants to GhosttyKey suffixes
local codes = {
  ["return"] = "ENTER",

  ["up"] = "ARROW_UP",
  ["down"] = "ARROW_DOWN",
  ["left"] = "ARROW_LEFT",
  ["right"] = "ARROW_RIGHT",

  ["["] = "LEFT_BRACKET",
  ["]"] = "RIGHT_BRACKET",
  ["\\"] = "BACKSLASH",
  ["/"] = "SLASH",
  [";"] = "SEMICOLON",


  ["0"] = "ZERO",
  ["1"] = "ONE",
  ["2"] = "TWO",
}

local GHOSTTY_MODS_SHIFT = 0x1
local GHOSTTY_MODS_CTRL  = 0x2
local GHOSTTY_MODS_ALT   = 0x4
local GHOSTTY_MODS_SUPER = 0x8
local GHOSTTY_MODS_CAPS_LOCK = 0x10
local GHOSTTY_MODS_NUM_LOCK  = 0x20

function input:push_text(data)
  self.text = self.text .. data
end

function input:push(data)
  self.queue = self.queue .. data
end

function input:drain()
  local text = self.text
  self.text = ""
  return text
end

function input:get_mods()
  local mods = 0
  if love.keyboard.isDown "lshift" or love.keyboard.isDown "rshift" then
    mods = bit.bor(mods, GHOSTTY_MODS_SHIFT)
  elseif love.keyboard.isDown "lctrl" or love.keyboard.isDown "rctrl" then
    mods = bit.bor(mods, GHOSTTY_MODS_CTRL)
  elseif love.keyboard.isDown "lalt" or love.keyboard.isDown "ralt" then
    mods = bit.bor(mods, GHOSTTY_MODS_ALT)
  end
  return mods
end

function input:get_code(scancode)
  return codes[scancode] or scancode:upper()
end

return input
