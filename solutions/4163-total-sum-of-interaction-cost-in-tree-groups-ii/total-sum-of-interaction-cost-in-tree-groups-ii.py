# O(n log n)
# pass in a list of edges [(a, b), (c, d), ...]
# get out a list of [(subtreeRoot, { node1 : node1Children, node2 : node2Children, ...}), ...]
# with edges == [] it returns [(0, {0: []})]
def centroidDecomp(edges):
    arrSize = 1
    for u, v in edges:
        if u >= arrSize: arrSize = u + 1
        if v >= arrSize: arrSize = v + 1
    adj = [[] for _ in range(arrSize)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    removed = [False] * arrSize
    sz = [0] * arrSize
    par = [-1] * arrSize
    res = []
    stack = [edges[0][0] if edges else 0]
    while stack:
        start = stack.pop()
        order = []
        dfs = [start]
        par[start] = -1
        while dfs:
            node = dfs.pop()
            order.append(node)
            for nxt in adj[node]:
                if nxt != par[node] and not removed[nxt]:
                    par[nxt] = node
                    dfs.append(nxt)
        total = len(order)
        for node in order:
            sz[node] = 1
        for node in reversed(order):
            if par[node] != -1:
                sz[par[node]] += sz[node]
        centroid = start
        while True:
            heavy = -1
            for nxt in adj[centroid]:
                if nxt != par[centroid] and not removed[nxt] and sz[nxt] * 2 > total:
                    heavy = nxt
                    break
            if heavy == -1:
                break
            centroid = heavy
        children = {centroid: []}
        bfs = [centroid]
        while bfs:
            node = bfs.pop()
            kids = children[node]
            for nxt in adj[node]:
                if not removed[nxt] and nxt not in children:
                    children[nxt] = []
                    kids.append(nxt)
                    bfs.append(nxt)
        res.append((centroid, children))
        removed[centroid] = True
        for nxt in adj[centroid]:
            if not removed[nxt]:
                stack.append(nxt)
    return res

class Solution:
    def interactionCosts(self, n: int, edges: list[list[int]], group: list[int]) -> int:
        trees = centroidDecomp(edges)
        
        def solveForTree(treeTup):
            root, children = treeTup
            res = 0

            def collect(node, gToSum, gFrq, currDepth):
                g = group[node]
                gToSum[g] += currDepth
                gFrq[g] += 1
                for child in children[node]:
                    collect(child, gToSum, gFrq, currDepth + 1)
            
            rootChildren = []
            for child in children[root]:
                gToSum = defaultdict(int)
                gFrq = defaultdict(int)
                collect(child, gToSum, gFrq, 1)
                rootChildren.append((gToSum, gFrq))

            accSum = defaultdict(int) # accumulated sum of group -> root distances for all paths
            accCount = defaultdict(int) # accumulated count of group -> root count of paths
            accCount[group[root]] += 1

            for childSum, childFrq in rootChildren:
                # new path total distances, for each group, its sum is going to occur the previous amount of count times
                # and the previous sum is going to add the new count
                for g in childSum:
                    total = childSum[g]
                    frq = childFrq[g]

                    newPathSum = 0
                    newPathSum += total * accCount[g]
                    newPathSum += accSum[g] * frq
                    res += newPathSum

                    accSum[g] += childSum[g]
                    accCount[g] += childFrq[g]
            
            return res

        return sum(solveForTree(tree) for tree in trees)


        