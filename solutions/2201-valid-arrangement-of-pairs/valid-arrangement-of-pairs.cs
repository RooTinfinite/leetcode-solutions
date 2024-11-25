public class Solution {
    public int[][] ValidArrangement(int[][] pairs) {
        var adjacencyList = new Dictionary<int, List<int>>();
        var inOutDegree = new Dictionary<int, int>();
        
        // Build graph and count in/out degrees
        foreach (var pair in pairs) {
            if (!adjacencyList.ContainsKey(pair[0])) {
                adjacencyList[pair[0]] = new List<int>();
            }
            adjacencyList[pair[0]].Add(pair[1]);
            
            inOutDegree[pair[0]] = inOutDegree.GetValueOrDefault(pair[0], 0) + 1;  // out-degree
            inOutDegree[pair[1]] = inOutDegree.GetValueOrDefault(pair[1], 0) - 1;  // in-degree
        }
        
        // Find starting node
        int startNode = pairs[0][0];
        foreach (var kvp in inOutDegree) {
            if (kvp.Value == 1) {
                startNode = kvp.Key;
                break;
            }
        }
        
        var path = new List<int>();
        var nodeStack = new Stack<int>();
        nodeStack.Push(startNode);
        
        while (nodeStack.Count > 0) {
            if (!adjacencyList.ContainsKey(nodeStack.Peek()) || 
                adjacencyList[nodeStack.Peek()].Count == 0) {
                path.Add(nodeStack.Pop());
            } else {
                var neighbors = adjacencyList[nodeStack.Peek()];
                int nextNode = neighbors[neighbors.Count - 1];
                nodeStack.Push(nextNode);
                neighbors.RemoveAt(neighbors.Count - 1);
            }
        }
        
        var arrangement = new List<int[]>();
        int pathSize = path.Count;
        
        for (int i = pathSize - 1; i > 0; --i) {
            arrangement.Add(new int[] { path[i], path[i-1] });
        }
        
        return arrangement.ToArray();
    }
}