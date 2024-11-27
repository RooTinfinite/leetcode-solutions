public class Solution {
    private void UpdateDistances(List<int>[] graph, int current, int[] distances) {
        int newDist = distances[current] + 1;
        
        foreach (int neighbor in graph[current]) {
            if (distances[neighbor] <= newDist) {
                continue;
            }
            
            distances[neighbor] = newDist;
            UpdateDistances(graph, neighbor, distances);
        }
    }
    
    public int[] ShortestDistanceAfterQueries(int n, int[][] queries) {
        int[] distances = new int[n];
        for (int i = 0; i < n; i++) {
            distances[i] = n - 1 - i;
        }
        
        List<int>[] graph = new List<int>[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new List<int>();
        }
        
        for (int i = 0; i < n - 1; i++) {
            graph[i + 1].Add(i);
        }
        
        List<int> answer = new List<int>();
        
        foreach (var query in queries) {
            int source = query[0];
            int target = query[1];
            
            graph[target].Add(source);
            distances[source] = Math.Min(distances[source], distances[target] + 1);
            UpdateDistances(graph, source, distances);
            
            answer.Add(distances[0]);
        }
        
        return answer.ToArray();
    }
}