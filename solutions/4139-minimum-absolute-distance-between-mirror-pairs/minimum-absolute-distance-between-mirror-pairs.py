class Solution(object):
    def minMirrorPairDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}
        n = len(nums)

        for i, v in enumerate(nums):
            mp[v] = i

        res = float('inf')

        for i, v in enumerate(nums):
            r = self.reverseNum(v)
            if r in mp and i < mp[r]:
                res = min(res, mp[r] - i)

        return -1 if res == float('inf') else res

    def reverseNum(self, x):
        return int(str(x)[::-1])