class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums)-1, -1, -1):
            v = nums.pop()
            a = bisect_left(nums, lower - v)
            b = bisect_right(nums, upper - v)

            ans += b - a
        
        return ans
          