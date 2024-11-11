from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        Find two numbers in the array that add up to the target.
        
        Args:
            numbers: A list of integers
            target: The target sum to find
            
        Returns:
            List[int]: Indices (1-based) of the two numbers that add up to target
        """
        seen_numbers = {}  # Maps number to its index (1-based)
        
        for current_index, current_number in enumerate(numbers, 1):
            complement = target - current_number
            
            if complement in seen_numbers:
                return [seen_numbers[complement], current_index]
                
            seen_numbers[current_number] = current_index