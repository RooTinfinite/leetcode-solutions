class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort() # Sort the input array
        count = 0 # Initialize count of valid triangles
        
        # Loop through all possible triplets using two pointers
        for i in range(len(nums) - 2):
            k = i + 2 # Initialize third pointer to i + 2
            
            # If the first element of the triplet is 0, move to the next element
            if nums[i] == 0:
                continue
                
            # If all remaining elements in the array are zero, break out of the loop
            if nums[i+1] == 0 and nums[-1] == 0:
                break
            
            # Loop through all possible second elements of the triplet
            for j in range(i + 1, len(nums) - 1):
                
                # Move the third pointer to the first element that is greater than or equal to the sum of the first two elements
                while k < len(nums) and nums[i] + nums[j] > nums[k]:
                    k += 1
                
                # The number of valid triangles that can be formed with the current pair of first two elements is the difference between the third pointer and the second pointer minus 1
                count += k - j - 1
        
        return count