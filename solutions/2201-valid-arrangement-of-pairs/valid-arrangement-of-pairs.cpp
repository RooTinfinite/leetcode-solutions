class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inOutDeg;
        
        // Build graph using bit operations
        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            inOutDeg[start] += 1 << 0;     // Increment out-degree using left shift
            inOutDeg[end] -= 1 << 0;       // Decrement in-degree using left shift
        }
        
        // Find start node using bit comparison
        int startNode = pairs[0][0];
        for (const auto& entry : inOutDeg) {
            if (entry.second == (1 << 0)) { // Compare with shifted 1
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
        
        // Reverse using bit operations for index calculation
        int n = path.size();
        for (int i = 0; i < (n >> 1); i++) {
            swap(path[i], path[n - 1 - i]);
        }
        
        return path;
    }
};