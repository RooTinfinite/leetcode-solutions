class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        
        # Create a copy of input array to work with
        values = nums.copy()
        
        # Forward pass - check and swap from left to right
        for i in range(n - 1):
            # Skip if elements are already in order
            if values[i] <= values[i + 1]:
                continue
            else:
                # Check if adjacent elements have same number of set bits
                if bin(values[i]).count('1') == bin(values[i + 1]).count('1'):
                    # Swap elements if they have same number of set bits
                    values[i], values[i + 1] = values[i + 1], values[i]
                else:
                    return False
        
        # Backward pass - check and swap from right to left
        for i in range(n - 1, 0, -1):
            # Skip if elements are already in order
            if values[i] >= values[i - 1]:
                continue
            else:
                # Check if adjacent elements have same number of set bits
                if bin(values[i]).count('1') == bin(values[i - 1]).count('1'):
                    # Swap elements if they have same number of set bits
                    values[i], values[i - 1] = values[i - 1], values[i]
                else:
                    return False
        
        # Array can be sorted if we reach here
        return True