from collections import defaultdict
from typing import List

class Solution:
    def minRunesToAdd(self, n: int, crystals: List[int], flowFrom: List[int], flowTo: List[int]) -> int:
        adjMap = {i: [] for i in range(n)}
        transposeMap = {i: [] for i in range(n)}
        stack = []

        # Build the original graph and its transpose
        for src, dsn in zip(flowFrom, flowTo):
            adjMap[src].append(dsn)
            transposeMap[dsn].append(src)

        visited = set()
        count = 0
        sccs = []

        # First DFS pass to fill the stack based on finishing times
        def dfs(node):
            visited.add(node)
            for nei in adjMap[node]:
                if nei not in visited:
                    dfs(nei)
            stack.append(node)

        # Second DFS pass on the transposed graph
        def transposedfs(node, scc):
            visited.add(node)
            scc.append(node)
            for nei in transposeMap[node]:  # Corrected to use transposeMap
                if nei not in visited:
                    transposedfs(nei, scc)

        # Step 1: Perform DFS on the original graph to fill the stack
        for node in range(n):
            if node not in visited:
                dfs(node)

        # Step 2: Perform DFS on the transposed graph in reverse finishing time order
        visited = set()
        while stack:
            node = stack.pop()
            if node not in visited:
                scc = []
                transposedfs(node, scc)
                sccs.append(scc)

        # Step 3: Map each node to its SCC index
        scc_map = {}
        for i, scc in enumerate(sccs):
            for node in scc:
                scc_map[node] = i

        # Step 4: Build the DAG of SCCs
        dag = {node:[]  for node in range(len(sccs))}
        for node in adjMap:
            for nei in adjMap[node]:
                if scc_map[node] != scc_map[nei]:  # Only add edges between different SCCs
                    dag[scc_map[node]].append(scc_map[nei])

        # Step 5: Calculate indegree for each SCC in the DAG
        indegree = [0] * n
        for node in dag:
            for nei in dag[node]:
                indegree[nei] += 1

        # Step 6: Track which SCCs contain crystals
        crystalComponents = set()
        for crystal in crystals:
            crystalComponents.add(scc_map[crystal])

        # Step 7: Count the number of SCCs that need new runes
        for node in dag:
            if indegree[node] == 0 and node not in crystalComponents:
                count += 1

        return count