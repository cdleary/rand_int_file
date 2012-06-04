-- Written by Mike Pall, see http://blog.cdleary.com/2012/06/simple-selfish-and-unscientific-shootout/#comment-546907272

local ffi = require("ffi")
ffi.cdef[[
typedef struct FILE FILE;
int fprintf(FILE *, const char *, ...);
]]
if #arg ~= 1 then
io.stderr:write("Usage: " .. arg[0] .. " <elem_count>\n")
os.exit(-1)
end    
local count = tonumber(arg[1])
math.randomseed(os.time())
local fp = io.open("vec_gen.out", "w")
for i = 1,count do
ffi.C.fprintf(fp, "%d\n", ffi.new("int", math.random(0, 2^31-1)))
end
fp:close()
