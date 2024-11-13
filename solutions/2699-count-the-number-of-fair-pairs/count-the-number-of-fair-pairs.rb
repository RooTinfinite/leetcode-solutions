def count_fair_pairs(nums, lower, upper)
    nums.sort!
    count_pairs(nums, upper) - count_pairs(nums, lower - 1)
end

def count_pairs(nums, target)
    count = 0
    left = 0
    right = nums.length - 1
    
    while left < right
        if nums[left] + nums[right] > target
            right -= 1
        else
            count += right - left
            left += 1
        end
    end
    count
end