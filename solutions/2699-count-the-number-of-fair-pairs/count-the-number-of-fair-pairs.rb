def bin_search(nums, l, r, target)
    while l <= r
        m = (l + r) / 2
        if nums[m] >= target
            r = m - 1
        else
            l = m + 1
        end
    end
    r
end

def count_fair_pairs(nums, lower, upper)
    nums.sort!
    res = 0
    nums.each_with_index do |num, i|
        low = lower - num
        up = upper - num
        res += bin_search(nums, i + 1, nums.length - 1, up + 1) - 
               bin_search(nums, i + 1, nums.length - 1, low)
    end
    res
end