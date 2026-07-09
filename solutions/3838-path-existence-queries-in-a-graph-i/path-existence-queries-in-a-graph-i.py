class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        """
        :type n: int
        :type nums: List[int]
        :type maxDiff: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        group = [0] * n
        currentGroup = 0
        
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                currentGroup += 1
            group[i] = currentGroup
        
        res = []
        for u, v in queries:
            res.append(group[u] == group[v])
        
        return res