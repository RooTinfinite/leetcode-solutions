class Solution:
    def countPairs(self, nums: List[List[int]], k: int) -> int:

        ans, d = 0,Counter(map(tuple,nums))
        R = [(i, k-i) for i in range(k+1)]

        for x, y in nums:
            d[(x, y)]-= 1
            ans+= sum(d[(x^i, y^j)] for i,j in R)

        return ans 