class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        modified_nums = []

        # Step 1: Apply operations on the array
        for index in range(0, n - 1):
            if (nums[index] == nums[index + 1]) and (nums[index] != 0):
                nums[index] *= 2
                nums[index + 1] = 0

        # Step 2: Move non-zero elements to the front
        for num in nums:
            if num != 0:
                modified_nums.append(num)

        # Step 3: Append zeros to maintain the original size
        while len(modified_nums) < n:
            modified_nums.append(0)

        return modified_nums