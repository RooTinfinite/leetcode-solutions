class Solution:
    def countFairPairs(self, a: List[int], l: int, u: int) -> int:
        a.sort()
        res = 0
        for i,v in enumerate(a):
            iMin = bisect_left(a, l-v, i+1)
            iMax = bisect_right(a, u-v, i+1)
            res += iMax-iMin
            
        return res