class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 2:
            return True
        for i in range(1, len(nums)):
            if (nums[i - 1] + nums[i]) % 2 == 0:
                return False
        
        return True