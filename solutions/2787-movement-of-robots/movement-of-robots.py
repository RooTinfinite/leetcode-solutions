class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n, m = len(nums), int(1e9 + 7)
        # Ignore the Collisions
        for i in range(n):
            if s[i] == 'L':
                nums[i] -= d
            else: 
                nums[i] += d
        
        # Sort according to position to calculate abs sum of each pair in O(N)
        nums.sort()

        pre = nums.copy()
        # Calculate Prefix Sum
        for i in range(1, n):
            pre[i] += pre[i - 1]
            pre[i] %= m

        ans = 0
        for i in range(1, n):
            # each jth index contributes to j * nums[j] - pre[j - 1]
            ans += i * nums[i] - pre[i - 1]
            ans %= m
        return ans