class Solution:
    
    # We don't use the state WHITE as such anywhere. Instead, the "null" value in the states array below is a substitute for WHITE.
    GRAY = 1
    BLACK = 2

    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = self.buildDigraph(n, edges)
        return self.leadsToDest(graph, source, destination, [None] * n)
        
    def leadsToDest(self, graph, node, dest, states):
        
        # If the state is GRAY, this is a backward edge and hence, it creates a Loop.
        if states[node] != None:
            return states[node] == Solution.BLACK
        
        # If this is a leaf node, it should be equal to the destination.
        if len(graph[node]) == 0:
            return node == dest
        
        # Now, we are processing this node. So we mark it as GRAY.
        states[node] = Solution.GRAY
        
        for next_node in graph[node]:
            
            # If we get a `false` from any recursive call on the neighbors, we short circuit and return from there.
            if not self.leadsToDest(graph, next_node, dest, states):
                return False;
        
        # Recursive processing done for the node. We mark it BLACK.
        states[node] = Solution.BLACK
        return True
        
    def buildDigraph(self, n, edges):
        graph = [[] for _ in range(n)]
        
        for edge in edges:
            graph[edge[0]].append(edge[1])
            
        return graph   