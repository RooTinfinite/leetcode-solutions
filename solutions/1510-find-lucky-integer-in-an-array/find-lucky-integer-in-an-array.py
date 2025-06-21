class Solution:
    def findLucky(self, arr: List[int]) -> int:
        res = Counter(arr)
        lucky = -1
        for i,j in res.items():
            if i == j:
                lucky = max(lucky , i)
        return lucky