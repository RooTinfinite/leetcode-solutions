def largest_combination(candidates)
    bit_max = 24
    max_set = 1
    mask = 1
    
    bit_max.times do |shift|
        count = 0
        
        candidates.each do |num|
            count += 1 if (num & mask) != 0
        end
        
        max_set = count if max_set < count
        mask <<= 1
    end
    
    max_set
end