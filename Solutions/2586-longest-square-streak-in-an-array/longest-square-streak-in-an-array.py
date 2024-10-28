class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        # Size of input array and variable to track maximum value
        n = len(nums)
        mx = 0
        
        # Create DP array to store streak lengths
        # Size 100001 because constraints mention nums[i] <= 10^5
        dp = [0] * 100001
        
        # Mark all numbers present in input array with 1
        # and track the maximum value
        for num in nums:
            dp[num] = 1
            mx = max(mx, num)
        
        # Initialize answer as -1 (for when no streak exists)
        ans = -1
        
        # Check each number from 2 up to the maximum value found
        for i in range(2, mx + 1):
            # If current number exists in our array AND
            # it's a perfect square (by checking if sqrt(i) * sqrt(i) equals i)
            sqrt_i = int(i ** 0.5)
            if dp[i] and sqrt_i * sqrt_i == i:
                # Add the streak length of its square root to current streak
                dp[i] = dp[i] + dp[sqrt_i]
                # Update answer with maximum streak found
                ans = max(ans, dp[i])
        
        # If longest streak is 1, it's not valid (need at least 2 numbers)
        if ans == 1:
            return -1
            
        return ans