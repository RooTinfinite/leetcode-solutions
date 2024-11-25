from collections import defaultdict
from typing import List

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        # Create adjacency list and track in/out degrees
        graph = defaultdict(list)
        degree = defaultdict(int)
        
        # Build graph in one pass
        for u, v in pairs:
            graph[u].append(v)
            degree[u] += 1
            degree[v] -= 1
        
        # Find starting node - first node with out degree > in degree
        start = pairs[0][0]  # Default to first node
        for node, deg in degree.items():
            if deg == 1:
                start = node
                break
        
        # Iterative Euler path implementation using stack
        stack = [start]
        path = []
        
        while stack:
            curr = stack[-1]
            if graph[curr]:
                next_node = graph[curr].pop()
                stack.append(next_node)
            else:
                node = stack.pop()
                if stack:
                    path.append([stack[-1], node])
        
        return path[::-1]

