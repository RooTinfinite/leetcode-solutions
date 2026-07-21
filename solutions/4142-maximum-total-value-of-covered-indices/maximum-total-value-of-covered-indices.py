class Solution:
    def maxTotal(self, nums: List[int], s: str) -> int:
        n = len(nums)
        ans = 0
        mini = float('inf')
        for i in range(n - 1, -1, -1):
            if s[i] == '1':
                # current value can be covered
                ans += nums[i]
                # smallest value in current block
                mini = min(mini, nums[i])
            else:
                # token from i+1 can move here
                if i + 1 < n and s[i + 1] == '1':
                    ans += nums[i]
                    # remove smallest value once
                    mini = min(mini, nums[i])
                    ans -= mini
                # start a new block
                mini = float('inf')
        return ans