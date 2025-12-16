class Solution:
    def minDeletions(self, s: str, qs: List[List[int]]) -> List[int]:
        n = len(s)
        # l[i] = 1 if s[i] == s[i+1] (identical), else 0
        l = list(starmap(eq, pairwise(s)))
        
        # O(n) BIT Construction
        bit = [0] + l
        for i in range(1, n):
            j = i + (i & -i)
            if j < n: bit[j] += bit[i]

        def flip(i):
            if not 0 <= i < n - 1: return
            # Determine if we are adding (+1) or removing (-1) an identical pair
            v = -1 if l[i] else 1
            l[i] ^= 1
            i += 1  # 1-based index for BIT
            while i < n:
                bit[i] += v
                i += i & -i

        ans = []
        for o, *oo in qs:
            if o == 1:
                i = oo[0]
                # Flipping s[i] affects pairs (i-1, i) and (i, i+1)
                flip(i - 1)
                flip(i)
            else:
                s, t = oo
                # res = Count of Identical Pairs (Direct Sum)
                res = 0
                
                # Optimized Query: Pruning common prefix calculation
                # Calculates query(t) - query(s) efficiently
                while t > s:
                    res += bit[t]
                    t &= t - 1  # Move t down
                while s > t:
                    res -= bit[s]
                    s &= s - 1  # Move s down
                
                ans.append(res)
        return ans