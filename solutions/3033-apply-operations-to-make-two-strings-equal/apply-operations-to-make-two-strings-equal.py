class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:

        @lru_cache(None)
        def dp(i,j):
            if i>j or j<0 or i>=len(s1): return 0

            return min(ones[i+1]-ones[i]+dp(i+2,j),
                       ones[j]-ones[j-1]+dp(i,j-2),
                       x+dp(i+1,j-1))

        s = int(s1,2)^int(s2,2)
        if s.bit_count() %2: return -1
        if s == 0: return 0

        ones, _ = zip(*filter(lambda x: x[1] == '1',
                              enumerate(bin(s)[2:])))
                           

        return dp(0,len(ones)-1) 