def can_sort_array(nums)
    n = nums.length
    values = nums.dup
    
    # Forward pass
    (0...n-1).each do |i|
        next if values[i] <= values[i + 1]
        
        if count_bits(values[i]) == count_bits(values[i + 1])
            values[i], values[i + 1] = values[i + 1], values[i]
        else
            return false
        end
    end
    
    # Backward pass
    (n-1).downto(1) do |i|
        next if values[i] >= values[i - 1]
        
        if count_bits(values[i]) == count_bits(values[i - 1])
            values[i], values[i - 1] = values[i - 1], values[i]
        else
            return false
        end
    end
    
    true
end

def count_bits(num)
    num.to_s(2).count('1')
end