# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    @result = []
    solve(nums, 0, nums.length - 1)
    @result
end

def solve(nums, l, r)
    if l == r
        @result.push(nums.clone)
        return
    end
    
    (l..r).each do |i|
        # Swap
        nums[l], nums[i] = nums[i], nums[l]
        
        # Recursive call
        solve(nums, l + 1, r)
        
        # Backtrack
        nums[l], nums[i] = nums[i], nums[l]
    end
end

