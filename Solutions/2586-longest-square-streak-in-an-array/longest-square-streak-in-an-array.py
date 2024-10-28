class Solution:
    def longestSquareStreak(self, nums: List[int]) ->int:
        # Convert nums to a sorted set to remove duplicates and have ordered numbers
        nums = sorted(set(nums))
        
        # Create a set for O(1) lookup time
        num_set = set(nums)
        
        # Track the maximum streak length found
        max_length = 0
        
        # Iterate through each number in sorted order
        for num in nums:
            # Initialize streak length for current number
            length = 0
            # Start with current number
            current = num
            
            # Keep squaring the number while it exists in our set
            while current in num_set:
                length += 1
                current = current ** 2
            
            # Only update max_length if we found a streak of length > 1
            if length > 1:
                max_length = max(max_length, length)
        
        # Return max_length if we found a valid streak, otherwise return -1
        return max_length if max_length > 1 else -1