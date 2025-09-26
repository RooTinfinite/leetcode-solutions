class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        # Initialize variables to keep track of the answer, the size of the array, and set the initial answer to the first element of the array.
        ans = 0
        n = len(nums)
        ans += nums[0]

        # Initialize variables to find the minimum values for the second and third subarrays.
        mini1 = float('inf')
        mini2 = float('inf')
        j = 1

        # Iterate through the array to find the minimum value (mini1) and its index (j) for the second subarray.
        for i in range(1, n):
            if nums[i] < mini1:
                mini1 = nums[i]
                j = i

        # Iterate through the array again to find the minimum value (mini2) for the third subarray, excluding the element at index j.
        for i in range(1, n):
            if nums[i] < mini2 and i != j:
                mini2 = nums[i]

        # Add the minimum values of the second and third subarrays to the answer.
        ans += mini1
        ans += mini2

        # Return the final minimum sum of costs.
        return ans