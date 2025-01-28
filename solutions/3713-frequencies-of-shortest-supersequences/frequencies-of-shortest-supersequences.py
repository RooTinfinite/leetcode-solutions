class Solution:
    def supersequences(self, bigrams: List[str]) -> List[List[int]]:
        edges = [[ord(u) - ord('a'), ord(v) - ord('a')] for u, v in bigrams]
        nodes = {x for uv in edges for x in uv}

        for length in range(len(nodes) + 1):
            good_doubles = []
            for doubles in combinations(nodes, length):
                adj = [[] for _ in range(26)]
                for u, v in edges:
                    if u not in doubles and v not in doubles:
                        adj[u].append(v)
                if not has_cycle(adj):
                    good_doubles.append(doubles)

            if good_doubles:
                break
                
        ans = []
        for doubles in good_doubles:
            row = [0] * 26
            for x in nodes: row[x] = 1
            for y in doubles: row[y] = 2
            ans.append(row)
        return ans


NEW, VISITING, DONE = range(3)
def has_cycle(adj):
    color = defaultdict(int)
    def dfs(node):
        if color[node] != NEW:
            return color[node] == VISITING
        color[node] = VISITING
        if any(dfs(nei) for nei in adj[node]):
            return True
        color[node] = DONE
        return False

    return any(dfs(u) for u in range(len(adj)))