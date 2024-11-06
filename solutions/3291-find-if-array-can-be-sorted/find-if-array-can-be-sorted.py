class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        # Store pairs of (min, max) values for each group of numbers with same bit count
        mm = []
        
        # Initialize first group with first number
        mm.append([nums[0], nums[0]])
        
        # Iterate through array starting from second element
        for i in range(1, len(nums)):
            # Get bit count of current and previous numbers
            cur = bin(nums[i]).count('1')
            prev = bin(nums[i-1]).count('1')
            
            # If bit counts are different, start a new group
            if cur != prev:
                mm.append([nums[i], nums[i]])
            
            # Update min and max values of current group
            mm[-1][0] = min(mm[-1][0], nums[i])
            mm[-1][1] = max(mm[-1][1], nums[i])
        
        # Check if groups can be sorted
        # For array to be sortable, max of previous group should be less than min of next group
        for i in range(1, len(mm)):
            if mm[i-1][1] > mm[i][0]:
                return False
        
        # If all groups can be sorted, return true
        return True

