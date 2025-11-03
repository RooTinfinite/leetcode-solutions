class Solution(object):
    def maxProduct(self, nums):
        nums = [abs(x) for x in nums]
        m1 = m2 = -100000
        for x in nums:
            if x > m1:
                m2, m1 = m1, x
            elif x > m2:
                m2 = x
        return m1 * m2 * 100000