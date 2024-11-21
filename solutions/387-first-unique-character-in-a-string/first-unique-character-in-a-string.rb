def first_uniq_char(input_str)
    first_unique = Float::INFINITY
    
    ('a'..'z').each do |c|
        if input_str.include?(c)
            if input_str.index(c) == input_str.rindex(c)
                first_unique = [first_unique, input_str.index(c)].min
            end
        end
    end
    
    first_unique == Float::INFINITY ? -1 : first_unique
end