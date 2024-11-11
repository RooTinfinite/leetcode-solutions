def prime_sub_operation(nums)
    max_element = get_max_element(nums)
    
    # Create Sieve of Eratosthenes array
    sieve = Array.new(max_element + 1, true)
    sieve[1] = false
    
    (2..Math.sqrt(max_element + 1).to_i).each do |i|
        if sieve[i]
            (i * i).step(max_element, i) do |j|
                sieve[j] = false
            end
        end
    end
    
    curr_value = 1
    i = 0
    
    while i < nums.length
        difference = nums[i] - curr_value
        
        return false if difference < 0
        
        if sieve[difference] == true || difference == 0
            i += 1
            curr_value += 1
        else
            curr_value += 1
        end
    end
    
    true
end

def get_max_element(nums)
    nums.max
end