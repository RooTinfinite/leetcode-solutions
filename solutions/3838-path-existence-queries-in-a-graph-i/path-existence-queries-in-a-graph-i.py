class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        cuts = [0]
        for i in range(1, n):
            if nums[i] - nums[i-1] > maxDiff:
                cuts.append(i)
        ans = []
        for ui, vi in queries:
            x = bisect.bisect_right(cuts, ui)
            y = bisect.bisect_right(cuts, vi)
            ans.append(x == y)
        return ans