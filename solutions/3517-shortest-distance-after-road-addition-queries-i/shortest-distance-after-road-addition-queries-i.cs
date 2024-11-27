public class Solution {
    public int[] ShortestDistanceAfterQueries(int n, int[][] queries) {
        List<List<int>> adj = new List<List<int>>();
        
        for (int i = 0; i < n; i++) {
            adj.Add(new List<int> { i + 1 });
        }
        
        List<int> res = new List<int>();
        foreach (var query in queries) {
            adj[query[0]].Add(query[1]);
            res.Add(ShortestPath(adj, n));
        }
        
        return res.ToArray();
    }
    
    private int ShortestPath(List<List<int>> adj, int n) {
        Queue<(int node, int length)> q = new Queue<(int, int)>();
        q.Enqueue((0, 0));
        HashSet<int> visit = new HashSet<int> { 0 };
        
        while (q.Count > 0) {
            var (cur, length) = q.Dequeue();
            
            if (cur == n - 1) return length;
            
            foreach (int nei in adj[cur]) {
                if (!visit.Contains(nei)) {
                    q.Enqueue((nei, length + 1));
                    visit.Add(nei);
                }
            }
        }
        return -1;
    }
}