class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        n = len(nums)
        concatenation_value = 0

        for i in range(n//2):
            concatenation_value += int(str(nums[i]) + str(nums[n-1-i]))

        if n % 2 != 0:
            concatenation_value += int(nums[n//2])

        return concatenation_value