#!/usr/local/bin/lua
-- Comment
-- # is not commet
--[[
Block Commet
--]]

local http=require'socket.http'
body,c,l,h = http.request('http://book.douban.com/subject/26416401/')
print('status line',l)
print('body',body)
