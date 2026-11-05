class Solution:
    def findColoredRoot(self, edges: list[list[int]], colors: str) -> int:
        n = len(colors)
        
        tree = [[] for _ in range(n)]
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        map = {'R': 'B', 'B': 'W', 'W': 'R'}
        
        def check(i: int, parent: int) -> bool:
            children = [node for node in tree[i] if node != parent]
            
            if len(children) > 2:
                return False

            return all(colors[child] == map[colors[i]] for child in children) and all(check(child, i) for child in children)
            
        for i in range(n):
            if len(tree[i]) < 3 and check(i, -1):
                return i

        return -1