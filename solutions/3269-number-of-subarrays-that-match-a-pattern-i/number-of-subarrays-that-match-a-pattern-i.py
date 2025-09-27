class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        n = len(nums)  # Size of the input array nums
        m = len(pattern)  # Size of the pattern array
        count = 0  # Initialize the count of matching subarrays

        # Iterate through all possible starting indices of the subarray
        for i in range(n):
            # Iterate through all possible ending indices of the subarray
            for j in range(i, n):
                # Check if the size of the current subarray is equal to m + 1
                if j - i + 1 == m + 1:
                    l = i  # Initialize a variable for tracking the current index in the subarray
                    flag = 0  # Initialize a flag to track if the subarray matches the pattern

                    # Iterate through the pattern and compare it with the subarray elements
                    for k in range(m):
                        # Check for the matching conditions based on the pattern values
                        if pattern[k] == 1 and nums[l + 1] > nums[l]:
                            # If pattern[k] is 1, check for strictly increasing condition
                            l += 1
                        elif pattern[k] == 0 and nums[l + 1] == nums[l]:
                            # If pattern[k] is 0, check for equal condition
                            l += 1
                        elif pattern[k] == -1 and nums[l + 1] < nums[l]:
                            # If pattern[k] is -1, check for strictly decreasing condition
                            l += 1
                        else:
                            # If any condition fails, set the flag and break out of the loop
                            flag = 1
                            break

                    # If the flag is still 0, the subarray matches the pattern, so increment the count
                    if flag == 0:
                        count += 1

        # Return the final count of matching subarrays
        return count
