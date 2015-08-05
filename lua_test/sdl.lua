#!/usr/local/bin/lua

local sdl = require "SDL"
local font = require "SDL.ttf"
local ret, err = sdl.init {
  sdl.flags.Video
}
if not ret then
  error(err)
end

--local ret, err = sdl.init ()
--if not ret then
  --error(err)
--end

--local win, err = SDL.createWindow {
  --title = "Image",
  --height = 100,
  --width = 100
--}
--if not win then
  --error(err)
--end
