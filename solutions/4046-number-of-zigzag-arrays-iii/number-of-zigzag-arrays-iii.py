import numpy as np

M = 10**9+7

mp = {}

def helper(k):
    res = np.ones((1, k), dtype=np.int64)
    m = np.array([[int(i + j + 1 < k) for j in range(k)] for i in range(k)], dtype=np.int64)
    for n in range(1, 201):
        res = (res @ m) % M
        mp[(n+1, k)] = int(res.sum() * 2 % M)

for k in range(1, 202):
    helper(k)

class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        k = r-l+1
        ans = 0
        mp1 = {}
        for i in range(-n, n+1):
            mp1[i] = pow(i, M-2, M)
        for i in range(1, n+2):
            c = mp[(n, i)]
            for j in range(1, n+2):
                if i!=j:
                    c *= (k-j)*mp1[i-j]
                    c %= M
            ans += c
            ans %= M
        return ans