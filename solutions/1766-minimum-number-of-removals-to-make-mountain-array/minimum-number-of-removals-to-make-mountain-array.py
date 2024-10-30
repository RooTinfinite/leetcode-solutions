class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        # Get the length of input array
        size = len(nums)
        
        # Arrays to store longest increasing subsequence lengths
        # left[i]: length of LIS from left to index i
        # right[i]: length of LIS from right to index i
        left = [0] * size
        right = [0] * size
        
        # First pass: Calculate LIS lengths from left to right
        dp = []  # Dynamic array to build LIS
        for i in range(size):
            # Find position to insert current number in sorted dp array
            idx = bisect_left(dp, nums[i])
            if idx == len(dp):
                # If number is larger than all elements in dp, append it
                dp.append(nums[i])
            else:
                # Replace element at idx with current number
                dp[idx] = nums[i]
            # Store length of LIS ending at index i
            left[i] = len(dp)
        
        # Second pass: Calculate LIS lengths from right to left
        dp = []  # Reset dp array for right to left pass
        for i in range(size - 1, -1, -1):
            # Same process as above, but moving right to left
            idx = bisect_left(dp, nums[i])
            if idx == len(dp):
                dp.append(nums[i])
            else:
                dp[idx] = nums[i]
            # Store length of LIS starting from index i
            right[i] = len(dp)
        
        # Third pass: Find minimum removals needed
        minRemove = size
        for i in range(size):
            # Check if current index can be peak of mountain
            # Need at least 2 elements on both sides
            if left[i] > 1 and right[i] > 1:
                # Calculate removals needed:
                # size - (left[i] + right[i] - 1)
                # -1 because peak is counted twice
                minRemove = min(minRemove, size - left[i] - right[i] + 1)
        
        return minRemove