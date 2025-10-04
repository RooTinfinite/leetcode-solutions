class KeyDefaultDict(dict):
    def __missing__(self, key): return key

class Solution:
    def countComponents(self, A, t):
        g = KeyDefaultDict()
        def find(x):
            if x != g[x]: g[x] = find(g[x])
            return g[x]
        def connect(x, y):
            g[find(g[y])] = find(g[x])       
        [connect(a, b) for a in A for b in range(a, t+1, a)]
        return sum(v == g[v] for v in A)