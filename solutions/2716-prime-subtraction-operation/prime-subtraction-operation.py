class Solution:
    def primeSubOperation(self, nums: list[int]) -> bool:
        def getMaxElement(nums):
            return max(nums)
        
        maxElement = getMaxElement(nums)
        
        # Store the sieve array
        sieve = [True] * (maxElement + 1)
        sieve[1] = False
        
        for i in range(2, int((maxElement + 1) ** 0.5) + 1):
            if sieve[i]:
                for j in range(i * i, maxElement + 1, i):
                    sieve[j] = False
        
        # Start by storing the currValue as 1, and the initial index as 0
        currValue = 1
        i = 0
        
        while i < len(nums):
            # Store the difference needed to make nums[i] equal to currValue
            difference = nums[i] - currValue
            
            # If difference is less than 0, then nums[i] is already less than
            # currValue. Return false in this case
            if difference < 0:
                return False
            
            # If the difference is prime or zero, then nums[i] can be made
            # equal to currValue
            if sieve[difference] or difference == 0:
                i += 1
                currValue += 1
            else:
                # Otherwise, try for the next currValue
                currValue += 1
        
        return True