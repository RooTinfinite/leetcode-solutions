MAXN = 10**5 + 5
spf = list(range(MAXN))

def sieve():
	spf[1] = 1

	for i in range(4, MAXN, 2):
		spf[i] = 2

	for i in range(3, ceil(sqrt(MAXN))):
		if (spf[i] == i):
			for j in range(i * i, MAXN, i):
				if (spf[j] == j):
					spf[j] = i

def factors(x: int):
	factors_set = set()

	while x != 1:
		factors_set.add(spf[x])
		x //= spf[x]

	return factors_set

sieve()

class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        df = {}
        uf = UnionFind(len(nums))
        for pos, num in enumerate(nums):
            for factor in factors(num):
                if factor in df:
                    uf.union(pos, df[factor])
                else:
                    df[factor] = pos
                    
        return uf.mx
            
class UnionFind:
    def __init__(self, n: int):
        self.root_lookup = list(range(n))
        self.rank_lookup = [1] * n
        self.mx = 1

    def find(self, num: int):
        root = self.root_lookup[num]
        while root != self.root_lookup[root]:
              root = self.root_lookup[root]
        self.root_lookup[num] = root
        return root
    
    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        if self.rank_lookup[xr] < self.rank_lookup[yr]:
            xr, yr = yr, xr
        self.root_lookup[yr] = xr
        self.rank_lookup[xr] += self.rank_lookup[yr]
        self.mx = max(self.mx,self.rank_lookup[xr])
        return True