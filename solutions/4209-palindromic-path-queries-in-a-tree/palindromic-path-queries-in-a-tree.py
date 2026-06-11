class Solution:
    def palindromePath(self, n: int, es: list[list[int]], S: str, qs: list[str]) -> list[bool]:
        pa = [0] * n
        deg = [0] * n
        deg[0] = 2  # Set root degree to avoid it being treated as a leaf
        for a, b in es:
            pa[a] ^= b; pa[b] ^= a  # Store XOR sum of neighbors
            deg[a] += 1; deg[b] += 1

        siz = [1] * n
        ch = [-1] * n
        qu = [i for i in range(n) if deg[i] == 1]  # Start from leaves
        for i in qu:
            p = pa[i]  # Current XOR sum contains only the parent
            s = siz[i]
            siz[p] += s
            if (c := ch[p]) == -1 or s > siz[c]:
                ch[p] = i  # Identify heavy child
            pa[p] ^= i  # Remove child from parent's XOR sum to isolate grandparent/parent
            deg[p] -= 1
            if deg[p] == 1:
                qu.append(p)
        qu.append(0)

        top = [-1] * n
        dfn = [-1] * n
        l = [0] * n
        t = 0
        for i in reversed(qu):  # Top-down traversal to establish HLD
            if ~dfn[i]: continue
            tt = i
            while ~i:
                top[i] = tt
                l[t] = 1 << ord(S[i]) - 97  # Map character to bitmask
                dfn[i] = t
                t += 1
                i = ch[i]
        
        # O(n) BIT construction
        bit = [0] + l
        for i in range(1, n + 1):
            j = i + (i & -i)
            if j <= n: bit[j] ^= bit[i]

        ans = []
        for qq in qs:
            if qq.startswith("u"):  # Point update logic
                _, i, c = qq.split()
                i = int(i)
                x = dfn[i]
                v = (1 << ord(c) - 97)
                d = v ^ l[x]
                l[x] = v
                x += 1
                while x <= n:
                    bit[x] ^= d
                    x += x & -x
            else:  # Path query logic
                _, a, b = qq.split()
                a, b = int(a), int(b)
                res = 0
                while top[a] != top[b]:
                    if dfn[top[a]] < dfn[top[b]]:
                        a, b = b, a
                    s, t = dfn[top[a]], dfn[a] + 1
                    while t > s:  # Efficient range XOR query
                        res ^= bit[t]; t &= t - 1
                    while s > t:
                        res ^= bit[s]; s &= s - 1
                    a = pa[top[a]]
                if dfn[a] > dfn[b]:
                    a, b = b, a
                s, t = dfn[a], dfn[b] + 1
                while t > s:
                    res ^= bit[t]; t &= t - 1
                while s > t:
                    res ^= bit[s]; s &= s - 1
                ans.append(res & (res - 1) == 0)  # Check if at most one bit is set
        return ans