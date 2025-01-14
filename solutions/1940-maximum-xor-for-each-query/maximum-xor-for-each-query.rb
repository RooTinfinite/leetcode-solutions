def get_maximum_xor(nums, maximum_bit)
    mask = (1 << maximum_bit) - 1
    n = nums.length
    res = Array.new(n)
    curr = 0
    
    n.times do |i|
        curr ^= nums[i]
        res[n-i-1] = ~curr & mask
    end
    
    res
end