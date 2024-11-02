class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Hash table to store number->index mapping
        ht = {}
        
        # Iterate through the array
        for i, num in enumerate(nums):
            # Check if complement (target - current number) exists in hash table
            if target - num in ht:
                # If found, return indices of both numbers
                return [ht[target - num], i]
                
            # Store current number and its index in hash table
            ht[num] = i
            
        # Return empty list if no solution found
        return []