class Solution:
    def findAnswer(self, parent: List[int], s: str) -> List[bool]:
        n = len(s)
        tree = defaultdict(list)
        self.res = [False for _ in s]

        # arrays will be sorted, because i-s are sorted
        for i, it in enumerate(parent):
            tree[it].append(i)
        
        MOD = int(1e9+7)
        h = 26
        hh = 31
        lastIdx = 0
        
        # annotate each node with its size
        sizes = [0 for _ in s]
        def dfs(root):
            sz = 1

            for child in tree[root]:
                sz += dfs(child)
            sizes[root] = sz
            return sz
        dfs(0)

        ls = []
        def postorder(root):
            sz = sizes[root]
            left = 0
            ss, revSS = 0, 0
            ss2, revSS2 = 0, 0

            for child in tree[root]:
                res = postorder(child)

                ss = (ss + pow(h, left, MOD) * res[0]) % MOD
                revSS = (pow(h, sizes[child], MOD) * revSS + res[1]) % MOD

                ss2 = (ss2 + pow(h, left, MOD) * res[2]) % MOD
                revSS2 = (pow(h, sizes[child], MOD) * revSS2 + res[3]) % MOD

                left += sizes[child]

            ss = (ss + pow(h, left, MOD) * (ord(s[root]))) % MOD
            revSS = (revSS * pow(h, 1, MOD) + (ord(s[root]))) % MOD

            ss2 = (ss2 + pow(h, left, MOD) * (ord(s[root]))) % MOD
            revSS2 = (revSS2 * pow(h, 1, MOD) + (ord(s[root]))) % MOD


            ls.append(s[root])

            if ss == revSS and ss2 == revSS2:
                self.res[root] = True
            return (ss, revSS, ss2, revSS2)

        postorder(0)
        return self.res