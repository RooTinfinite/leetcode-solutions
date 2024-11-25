class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> cnt;
        
        // Build graph and count in/out degrees
        for (const auto& p : pairs) {
            graph[p[0]].push_back(p[1]);
            cnt[p[0]]++;
            cnt[p[1]]--;
        }
        
        // Find starting node (head)
        int start = pairs[0][0];
        for (const auto& [node, degree] : cnt) {
            if (degree == 1) {
                start = node;
                break;
            }
        }
        
        // Use bit shifting for stack operations
        vector<int> route;
        stack<int> st;
        st.push(start);
        
        while (!st.empty()) {
            auto& edges = graph[st.top()];
            if (edges.empty()) {
                route.push_back(st.top());
                st.pop();
            } else {
                int next = edges.back();
                st.push(next);
                edges.pop_back();
            }
        }
        
        // Build result using bit shifting for size calculations
        vector<vector<int>> result;
        int size = route.size();
        result.reserve(size - 1);
        
        for (int i = size - 1; i > 0; --i) {
            result.push_back({route[i], route[i-1]});
        }
        
        return result;
    }
};