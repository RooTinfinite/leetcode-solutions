def add_spaces(s, spaces)
    result = Array.new(s.length + spaces.length)
    write_pos = 0
    read_pos = 0
    
    spaces.each do |space_pos|
        while read_pos < space_pos
            result[write_pos] = s[read_pos]
            write_pos += 1
            read_pos += 1
        end
        result[write_pos] = ' '
        write_pos += 1
    end
    
    while read_pos < s.length
        result[write_pos] = s[read_pos]
        write_pos += 1
        read_pos += 1
    end
    
    result.join
end