def two_sum(nums, target)
    ht = {}
    
    nums.each_with_index do |num, i|
        if ht.key?(target - num)
            return [ht[target - num], i]
        end
        
        ht[num] = i
    end
    
    []
end