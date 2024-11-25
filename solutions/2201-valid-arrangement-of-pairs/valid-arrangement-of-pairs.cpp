class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inOutDeg;
        
        // Build graph and calculate in/out degrees
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            inOutDeg[start]++;  // out-degree
            inOutDeg[end]--;    // in-degree
        }
        
        // Find starting node (node with out-degree > in-degree)
        int startNode = pairs[0][0];  // default start
        for (const auto& entry : inOutDeg) {
            if (entry.second == 1) {
                startNode = entry.first;
                break;
            }
        }
        
        vector<vector<int>> path;
        function<void(int)> dfs = [&](int curr) {
            while (!graph[curr].empty()) {
                int nextNode = graph[curr].back();
                graph[curr].pop_back();
                dfs(nextNode);
                path.push_back({curr, nextNode});
            }
        };
        
        dfs(startNode);
        reverse(path.begin(), path.end());
        return path;
    }
};