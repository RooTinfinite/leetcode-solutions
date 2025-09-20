class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        l, r = 0, len(nums) - 1
        avg = {}
        while l < r:
            currAvg = (nums[l] + nums[r]) / 2
            if currAvg in avg:
                avg[currAvg] += 1
            else:
                avg[currAvg] = 1
            l += 1
            r -= 1 
        return len(avg.keys())