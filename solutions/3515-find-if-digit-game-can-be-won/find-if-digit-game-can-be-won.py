class Solution:
    def canAliceWin(self, nums):
        dd, sd = 0, 0
        for i in nums:
            if i // 10 != 0:
                dd += i
            else:
                sd += i
        if abs(dd - sd) > 0:
            return True
        return False