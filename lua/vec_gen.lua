function main(args)
    if #args ~= 1 then
        io.stderr:write("Usage: " .. args[0] .. " <elem_count>\n")
        os.exit(-1)
    end

    local count = tonumber(args[1])

    math.randomseed(os.time())

    local upper = math.floor(2^32-1)

    io.output(io.open("vec_gen.out", "w"))
    for i = 1,count do
        local r = math.random(0, upper)
        io.write(r)
        io.write("\n")
    end

    io.close()
end

main(arg)
