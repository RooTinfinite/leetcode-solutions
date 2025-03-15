class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def candi(val):
            c = 0
            for pile in candies:
                c += pile // val
            return c >= k

        left = 1
        right = max(candies)
        res = 0

        while left <= right:
            mid = (left + right) // 2
            if candi(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1 
           
        return res
