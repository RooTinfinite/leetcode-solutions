from typing import List

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        target = len(graph) - 1
        results = []
        
        # curr_node: The node we are currently visiting
        # path: The sequence of nodes visited so far
        def dfs(curr_node, path):
            # Base Case: If we reached the target, save the path
            if curr_node == target:
                # We append a copy of the path (list(path)) because lists 
                # are mutable references in Python.
                results.append(list(path))
                return

            # Recursive Step: Check all neighbors of the current node
            for neighbor in graph[curr_node]:
                # 1. Choose - Add neighbor to path
                path.append(neighbor)
                
                # 2. Explore - Recurse deeper
                dfs(neighbor, path)
                
                # 3. Un-choose (Backtrack) - Remove neighbor to try the next one
                path.pop()

        # Start DFS from node 0, with the initial path containing just [0]
        dfs(0, [0])
        
        return results