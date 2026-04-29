class Solution {
    
    // We don't use the state WHITE as such anywhere. Instead, the "null" value in the states array below is a substitute for WHITE.
    enum Color { GRAY, BLACK };
    
    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        
        List<Integer>[] graph = buildDigraph(n, edges);
        return leadsToDest(graph, source, destination, new Color[n]);
    }
    
    private boolean leadsToDest(List<Integer>[] graph, int node, int dest, Color[] states) {
        
        // If the state is GRAY, this is a backward edge and hence, it creates a loop.
        if (states[node] != null) {
            return states[node] == Color.BLACK;
        }
        
        // If this is a leaf node, it should be equal to the destination.
        if (graph[node].isEmpty()) {
            return node == dest;
        }
        
        // Now, we are processing this node. So we mark it as GRAY
        states[node] = Color.GRAY;
        
        for (int next : graph[node]) {
            
            // If we get a `false` from any recursive call on the neighbors, we short circuit and return from there.
            if (!leadsToDest(graph, next, dest, states)) {
                return false;
            }
        }
        
        // Recursive processing done for the node. We mark it BLACK
        states[node] = Color.BLACK;
        return true;
    }
    
    private List<Integer>[] buildDigraph(int n, int[][] edges) {
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
        }
        
        return graph;
    }
}