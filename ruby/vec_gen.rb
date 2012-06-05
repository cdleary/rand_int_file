def main()
    if ARGV.length != 1 then
        warn "Usage: #{$0} <elem_count>"
        exit -1
    end

    count = ARGV[0].to_i
    file = File.open "vec_gen.out", "w"
    upper = 2147483647

    for i in 1..count do
        r = rand(upper)
        file.write r
        file.write "\n"
    end
end

main()
