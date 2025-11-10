
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # List to store non-decreasing segments as (start_index, length)
        incs = []
        ind = 0           # Start index of current segment
        curr = nums[0]    # Current value to compare
        lennow = 1        # Length of current segment
        
        # Identify all non-decreasing segments
        for i in range(1, len(nums)):
            n = nums[i]
            if n < curr:
                # Current segment ends, save it
                incs.append((ind, lennow))
                ind = i       # Start new segment
                lennow = 1
            else:
                lennow += 1
            curr = n
        else:
            # Append the last segment
            incs.append((ind, lennow))
        
        maxl = 1  # Initialize maximum length
        
        # Merge consecutive segments if possible
        for x in range(len(incs) - 1):
            ind, leng = incs[x][0], incs[x][1]
            nexti, nextl = incs[x+1][0], incs[x+1][1]

            # If next segment has length > 1, check if it can extend current segment
            if nextl > 1:
                l1, l2 = nums[nexti-2], nums[nexti-1]  # last two elements of current segment
                n1, n2 = nums[nexti], nums[nexti+1]    # first two elements of next segment
                # Merge full next segment if boundary conditions allow
                if n2 >= l2 or n1 >= l1:
                    leng += nextl
                else:
                    leng += 1  # Otherwise, can only add one element
            else:
                # Next segment has length 1, add one element
                leng += 1

            if leng > maxl:
                maxl = leng
        
        # Handle the last segment separately
        if len(incs) > 1:
            leng = incs[-1][1] + 1
        else:
            leng = incs[-1][1]
        if leng > maxl:
            maxl = leng
        
        return maxl