class Solution(object):
    def countConsistent(self, nums):
        n = len(nums)
        cnt = 0
        for i in range(n):
            add = nums[i]
            min_val = nums[i]
            for j in range(i, n):
                add &= nums[j]
                if nums[j] < min_val:
                    min_val = nums[j]
                if add == min_val:
                    cnt += 1
        return cnt