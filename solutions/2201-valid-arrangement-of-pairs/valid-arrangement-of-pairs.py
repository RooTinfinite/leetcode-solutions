from collections import defaultdict
from typing import List

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        # Create detailed graph structures
        graph = defaultdict(list)
        in_degree = defaultdict(int)
        out_degree = defaultdict(int)
        
        # Build comprehensive graph information
        for start, end in pairs:
            graph[start].append(end)
            out_degree[start] += 1
            in_degree[end] += 1
        
        # Carefully find the starting node
        start_node = pairs[0][0]
        for node in graph:
            if out_degree[node] - in_degree[node] == 1:
                start_node = node
                break
        
        result = []
        
        # Methodical depth-first traversal
        def explore_path(current_node):
            while graph[current_node]:
                next_node = graph[current_node].pop()
                explore_path(next_node)
                result.append([current_node, next_node])
        
        # Execute traversal
        explore_path(start_node)
        
        # Return reversed path for correct order
        return result[::-1]