class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        # Get length of input array
        n = len(nums)
        
        # First pass: Calculate longest increasing subsequence from right to left
        t, suf = [], [0] * n  # t is temp array for binary search, suf stores lengths
        for i in range(n - 1, 0, -1):
            # Find position where nums[i] would fit in sorted array t
            p = bisect_left(t, nums[i])
            if p < len(t):
                # If position exists, update suffix array and t
                suf[i] = p
                t[p] = nums[i]
            else:
                # If position doesn't exist, append to t
                suf[i] = len(t)
                t.append(nums[i])
        
        # Second pass: Calculate longest increasing subsequence from left to right
        # and find maximum mountain length
        t, pre, res = [], 0, 0  # Reset t, pre tracks current LIS length
        for i, x in enumerate(nums):
            # Find position where current number would fit
            p = bisect_left(t, x)
            if p < len(t):
                # If position exists, update prefix length and t
                pre = p
                t[p] = x
            else:
                # If position doesn't exist, append to t
                pre = len(t)
                t.append(x)
            
            # Check if we can form a mountain (need at least 1 element on each side)
            if pre >= 1 and suf[i] >= 1:
                # Update maximum mountain length (pre + suf[i] + 1)
                res = max(res, pre + suf[i] + 1)
        
        # Return minimum removals needed
        # Total length minus maximum mountain length
        return n - res