def minimum_size(nums, max_ops)
    low, high = 1, nums.max
    while low < high
        mid = (low + high) / 2
        ops = nums.sum { |n| (n - 1) / mid }
        ops <= max_ops ? high = mid : low = mid + 1
    end
    high
end