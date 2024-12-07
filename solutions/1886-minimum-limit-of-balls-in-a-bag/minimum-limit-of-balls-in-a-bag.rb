def can_divide(nums, max_balls, max_operations)
    ops = 0
    nums.each do |n|
        ops += (n.to_f / max_balls).ceil - 1
        return false if ops > max_operations
    end
    true
end

def minimum_size(nums, max_operations)
    left = 1
    right = nums.max
    res = right
    
    while left < right
        mid = left + (right - left) / 2
        if can_divide(nums, mid, max_operations)
            right = mid
            res = right
        else
            left = mid + 1
        end
    end
    res
end