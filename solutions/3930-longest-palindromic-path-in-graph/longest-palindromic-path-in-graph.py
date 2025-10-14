class Solution:
    def maxLen(self, n: int, edges: List[List[int]], label: str) -> int:
        # Solution 2: improved from sol 1, easier to read
        if n == 0:
            return 0

        # Complete graph (a clique) shortcut (visit nodes in any order)
        if len(edges) == n * (n - 1) // 2:
            freq = {}
            for ch in label:
                freq[ch] = freq.get(ch, 0) + 1
            half_pairs = 0
            odd_center = 0
            for count in freq.values():
                half_pairs += count // 2
                if count % 2:
                    odd_center = 1
            return half_pairs * 2 + odd_center # Total palindrome length

        # Build Adjacency List
        adjacency = [[] for _ in range(n)]
        for u, v in edges:
            adjacency[u].append(v)
            adjacency[v].append(u)

        bit_masks = [1 << i for i in range(n)] # Visited set of nodes as int bitmask
        max_length = 1
        queue = deque() # tuples (left, right, mask) of candidate pali path & bitmask
        visited = set() # integer keys to avoid revisiting same state

        # Seed palindromes of length 2 and 3
        for u in range(n):
            for v in adjacency[u]:
                # Length 2: direct edge w/ matching labels
                if u < v and label[u] == label[v]:
                    mask2 = bit_masks[u] | bit_masks[v]
                    key2 = (mask2 << 8) | (u << 4) | v # pack (mask, left, right) into an int key
                    queue.append((u, v, mask2))
                    visited.add(key2)
                    if 2 > max_length:
                        max_length = 2
                # Length 3: two hop path u-v-w w/ matching ends
                for w in adjacency[v]:
                    if w != u and label[u] == label[w]:
                        mask3 = bit_masks[u] | bit_masks[v] | bit_masks[w]
                        x, y = (u, w) if u < w else (w, u)
                        key3 = (mask3 << 8) | (x << 4) | y # Pack (mask, left, right) into an int key
                        if key3 not in visited:
                            queue.append((x, y, mask3))
                            visited.add(key3)
                            if 3 > max_length:
                                max_length = 3

        # BFS extension: pop a state and prune branch 
        while queue:
            left, right, mask = queue.popleft()
            length = mask.bit_count()       # Number of visited nodes
            if length + (n - length) <= max_length:
                continue                                     
            for nl in adjacency[left]:      # Expand both ends
                if mask & bit_masks[nl]:
                    continue                # Skip if nl already visited
                for nr in adjacency[right]:
                    if nl == nr or mask & bit_masks[nr]:
                        continue            # Skip collision or visited
                    if label[nl] == label[nr]: # Form the new visited mask
                        new_mask = mask | bit_masks[nl] | bit_masks[nr]
                        x, y = (nl, nr) if nl < nr else (nr, nl)
                        key = (new_mask << 8) | (x << 4) | y
                        if key in visited:
                            continue        # Skip seen state
                        visited.add(key)
                        queue.append((x, y, new_mask))
                        count = new_mask.bit_count()
                        if count > max_length:
                            max_length = count
                            if max_length == n:
                                return n    # Early exit
        return max_length


        # Solution 1: competition submission
        if n == 0: return 0
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v); g[v].append(u)

        ml = 1
        q = deque()
        vs = set()
        for i in range(n):
            for j in g[i]:
                if i < j and label[i] == label[j]:
                    mk = (1 << i) | (1 << j)
                    s = (i, j, mk)
                    q.append(s); vs.add(s)
                    if 2 > ml: ml = 2

        for c in range(n):
            nb = g[c]
            for x in range(len(nb)):
                for y in range(x + 1, len(nb)):
                    u, v = nb[x], nb[y]
                    if label[u] == label[v]:
                        mk = (1 << u) | (1 << c) | (1 << v)
                        u0, v0 = (u, v) if u < v else (v, u)
                        s = (u0, v0, mk)
                        if s not in vs:
                            q.append(s); vs.add(s)
                            if 3 > ml: ml = 3
                                
        while q:
            u, v, mk = q.popleft()
            for a in g[u]:
                if (mk >> a) & 1: continue
                for b in g[v]:
                    if (mk >> b) & 1 or a == b: continue
                    if label[a] == label[b]:
                        nm = mk | (1 << a) | (1 << b)
                        a0, b0 = (a, b) if a < b else (b, a)
                        s = (a0, b0, nm)
                        if s not in vs:
                            vs.add(s); q.append(s)
                            cnt = bin(nm).count('1')
                            if cnt > ml: ml = cnt
        return ml



        # ((6, [[0,1], [1,2], [1,3], [3,4], [3,5]], "ababae"), 4),
        # ((6, [[0,1], [1,2], [1,3], [3,4], [3,5]], "abcdef"), 1),

        # Chain of 13
        # 14
        # [[0, 1], [1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7], [7, 8], [8, 9], [9, 10], [10, 11], [11, 12], [12, 13]]
        # "abcdefghijklmn"

        # Star w/ node 0 at center
        # 14
        # [[0, 1], [0, 2], [0, 3], [0, 4], [0, 5], [0, 6], [0, 7], [0, 8], [0, 9], [0, 10], [0, 11], [0, 12], [0, 13]]
        # "aaaaaaaaaaaaaa"

        # Complete graph (clique)
        # 14
        # [[0, 1], [0, 2], [0, 3], [0, 4], [0, 5], [0, 6], [0, 7], [0, 8], [0, 9], [0, 10], [0, 11], [0, 12], [0, 13], [1, 2], [1, 3], [1, 4], [1, 5], [1, 6], [1, 7], [1, 8], [1, 9], [1, 10], [1, 11], [1, 12], [1, 13], [2, 3], [2, 4], [2, 5], [2, 6], [2, 7], [2, 8], [2, 9], [2, 10], [2, 11], [2, 12], [2, 13], [3, 4], [3, 5], [3, 6], [3, 7], [3, 8], [3, 9], [3, 10], [3, 11], [3, 12], [3, 13], [4, 5], [4, 6], [4, 7], [4, 8], [4, 9], [4, 10], [4, 11], [4, 12], [4, 13], [5, 6], [5, 7], [5, 8], [5, 9], [5, 10], [5, 11], [5, 12], [5, 13], [6, 7], [6, 8], [6, 9], [6, 10], [6, 11], [6, 12], [6, 13], [7, 8], [7, 9], [7, 10], [7, 11], [7, 12], [7, 13], [8, 9], [8, 10], [8, 11], [8, 12], [8, 13], [9, 10], [9, 11], [9, 12], [9, 13], [10, 11], [10, 12], [10, 13], [11, 12], [11, 13], [12, 13]]
        # "aaaaaaaaaaaaaa"