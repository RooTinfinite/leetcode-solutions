class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] < nums[i - 1]:
                nums[i - 1] = self.findNum(nums[i], nums[i - 1])
                if nums[i - 1] == -1: return -1
                ans += 1
        return ans
    
    def findNum(self, n1, n2):
        for i in range(2, n1 + 1):
            if n2 % i == 0: return i
        return -1