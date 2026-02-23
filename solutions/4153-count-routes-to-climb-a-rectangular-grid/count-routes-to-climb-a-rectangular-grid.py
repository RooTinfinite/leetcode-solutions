
class Solution:
    def numberOfRoutes(self, g: List[str], d: int) -> int:
        mod = 1e9 + 7
        n, m = len(g), len(g[0])
        D = floor(sqrt(d**2-1))
        ar = [0]*m
        def helper(pre, i, d):
            nonlocal mod
            a, b = max(i-d-1, -1), min(len(ar)-1, i+d)
            l, r = pre[a] if a >= 0 else 0, pre[b]
            return (r-l) % mod
            
        for i in range(m): 
            if g[0][i] == '.': ar[i] = 1
        pre = [0]*m
        for i in range(m): pre[i] = (pre[i-1] + ar[i]) % mod
        for i in range(m): 
            if g[0][i] == '.': ar[i] = helper(pre, i, d)

        # print(ar)
        for i in range(1, n):
            cr = [0]*m
            pre = [0]*m
            for j in range(m): pre[j] = (pre[j-1] + ar[j]) % mod
            for j in range(m): 
                if g[i][j] == '.': cr[j] = helper(pre, j, D) 
            pre = [0]*m
            for j in range(m): pre[j] = (pre[j-1] + cr[j]) % mod
            for j in range(m): 
                if g[i][j] == '.': cr[j] = helper(pre, j, d) 
            ar = cr

        # print(ar)
        return int(sum(ar) % mod)