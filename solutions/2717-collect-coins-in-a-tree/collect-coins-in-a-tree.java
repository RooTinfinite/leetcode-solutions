class Solution {
    private List<Integer>[] graph;
    private Queue<Integer> queue;
    int []degree;
    private void buildGraph(int n, int [][]edges) {
        degree = new int[n];
        graph = new ArrayList[n];
        for(int i = 0; i < n; i += 1) { graph[i] = new ArrayList<>(); }
        for(int []edge : edges) { 
            graph[edge[0]].add(edge[1]); graph[edge[1]].add(edge[0]);
            degree[edge[0]] += 1; degree[edge[1]] += 1;
        }
    }
    
    public int collectTheCoins(int[] coins, int[][] edges) {
        // idea : use topological sorting
        int totalEdges = edges.length, n = coins.length;
        System.out.println(n);
        buildGraph(n, edges);
        queue = new LinkedList<>();
        for(int i = 0; i < n; i += 1) { if(degree[i] == 1 && coins[i] == 0) { queue.add(i); }} // solve for non coins first
        while(!queue.isEmpty()) {
            int nodeToRemove = queue.remove();
            totalEdges -= 1;
            for(int child : graph[nodeToRemove]) {
                if(--degree[child] == 1 && coins[child] == 0) {
                    queue.add(child);
                }
            }
        }

        for(int i = 0; i < n; i += 1) { if(degree[i] == 1 && coins[i] == 1) { queue.add(i); }} // solve for coins next
        totalEdges -= queue.size();
        for(int element : queue) {
            degree[element] -= 1;
            for(int child : graph[element]) {
                if(child == element) continue;
                if(--degree[child] == 1) totalEdges -= 1;
            }
        }
        return Math.max(0, 2 * totalEdges);
    }
}


// 0 --> 1
// 1 --> 2
// 2 --> 2
// 3 --> 2
// 4 --> 2
// 5 --> 1
