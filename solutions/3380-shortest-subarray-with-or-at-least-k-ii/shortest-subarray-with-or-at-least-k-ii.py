class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        min_length = float('inf')
        or_to_index = {}  # tracks leftmost index for each OR value
        
        for right, num in enumerate(nums):
            # Update existing OR values with new number
            new_or_values = {or_val | num: left for or_val, left in or_to_index.items()}
            # Add the new number itself
            new_or_values[num] = right
            or_to_index = new_or_values
            
            # Check for valid subarrays
            for or_val, left in or_to_index.items():
                if or_val >= k:
                    min_length = min(min_length, right - left + 1)
                    
        return min_length if min_length != float('inf') else -1