class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        
        HashMap<Integer, Set<Integer>> graph1 = buildGraph(edges1);
        HashMap<Integer, Set<Integer>> graph2 = buildGraph(edges2);

        int n = graph1.size();
        int m = graph2.size();

        int[] nodeColor1 = new int[n];
        
        int[] color1 = new int[2];
        dfs(graph1, color1, 0, -1, 0, nodeColor1);

        int[] nodeColor2 = new int[m];

        int[] color2 = new int[2];
        dfs(graph2, color2, 0, -1, 0, nodeColor2);

        int[] ans = new int[n];

        for(int i=0;i<n;i++) {
            if(nodeColor1[i] == 0) {
                ans[i] = Math.max(color1[0] + color2[1] , color1[0] + color2[0]);
            } else {
                ans[i] = Math.max(color1[1] + color2[1] , color1[1] + color2[0] );
            }
        }

        return ans;
        
    }


    private void dfs(HashMap<Integer, Set<Integer>> graph, int[] color, int u, int p, int lastColor, int[] nodeColor) {
        nodeColor[u] = lastColor;
        color[lastColor]++;
        for(int v: graph.get(u)) {
            if(v==p) continue;
            dfs(graph, color, v, u, 1-lastColor, nodeColor);
        }
    }


    private HashMap<Integer, Set<Integer>> buildGraph(int[][] edges) {
        HashMap<Integer, Set<Integer>> graph = new HashMap<>();

        for(int[] edge: edges) {
            int a = edge[0];
            int b = edge[1];
            graph.computeIfAbsent(a, k->new HashSet<>()).add(b);
            graph.computeIfAbsent(b, k->new HashSet<>()).add(a);
        }

        return graph;
    }

}