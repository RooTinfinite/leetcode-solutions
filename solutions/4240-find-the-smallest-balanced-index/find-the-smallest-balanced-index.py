class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        lsum, rprod = sum(nums), 1
        for i in reversed(range(len(nums))):
            lsum -= nums[i]  # Update from sum(nums[0..i]) -> sum(nums[0..i-1])
            if lsum == rprod:
                return i
            if lsum < rprod:  # rprod can only increase, while lsum only decrease, so there no more matches
                break

            rprod *= nums[i]  # Update from prod(nums[i+1...n-1]) -> prod(nums[i..n-1])

        return -1