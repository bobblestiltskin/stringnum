-- this computes projecteuler.net problem 020

cfact = require 'mylib'

local last = 100
local factorial = "1"
for i = 1, last do
  factorial = cfact.mul_int_string(i,factorial)
end

local fstring = tostring(factorial)
local flen = string.len(fstring) 
      
local fsum = 0
for i = 1, flen do
  fsum = tonumber(string.sub(fstring, i, i)) + fsum
end

print(fsum)
