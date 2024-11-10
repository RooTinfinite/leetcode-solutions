def minimum_subarray_length(nums, k)
    return 1 if k == 0
    shortest = nums.length + 1
    count = Array.new(32, 0)
    val = 0
    start = 0
    
    (0...nums.length).each do |i|
        num = nums[i]
        val |= num
        ibit = 0
        while num != 0
            count[ibit] += num & 1
            num >>= 1
            ibit += 1
        end
        
        while val >= k && start < nums.length
            shortest = [shortest, i - start + 1].min
            num = nums[start]
            start += 1
            ibit = 0
            while num != 0
                count[ibit] -= num & 1
                if count[ibit] == 0
                    val &= ~(1 << ibit)
                end
                num >>= 1
                ibit += 1
            end
        end
    end
    
    shortest == nums.length + 1 ? -1 : shortest
end