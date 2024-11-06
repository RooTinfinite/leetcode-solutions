class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        # Store groups of numbers with same bit count
        groups = []
        # Current group being built
        curr = []
        # Track bit count of current group
        currBits = None
        
        # Iterate through each number
        for num in nums:
            # If this is start of first group, set the bit count
            if not currBits:
                currBits = num.bit_count()
            
            # If number has same bits as current group, add to current group
            if num.bit_count() == currBits:
                curr.append(num)
            # If different bit count, start new group
            else:
                currBits = num.bit_count()
                groups.append(curr)
                curr = [num]
        
        # Add final group if exists
        if curr:
            groups.append(curr)

        # Create result by sorting each group internally
        out = []
        for g in groups:
            out += sorted(g)
            
        # Check if result matches fully sorted array
        # If equal, means we can sort by swapping within groups
        return out == sorted(nums)