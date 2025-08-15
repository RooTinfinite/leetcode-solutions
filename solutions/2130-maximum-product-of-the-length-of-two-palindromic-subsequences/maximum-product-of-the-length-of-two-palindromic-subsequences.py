class Solution:
    def maxProduct(self, s: str) -> int:

        n, d = len(s), defaultdict(int)

        for mask in range(1<<n):                                # <-- 1
            sub = [s[i] for i in range(n) if mask & (1<<i)]     #

            if sub == sub[::-1]: d[mask] = len(sub)             # <-- 2

        return max(d[mask1] * d[mask2] for mask1, mask2         # <-- 3
                    in combinations(d,2) if mask1 & mask2 == 0) # <-- 4