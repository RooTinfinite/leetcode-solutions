class Solution {
public:
    int recursion(int mask, int n, vector<int> &indegree, vector<vector<int>> &graph, vector<int> &score, vector<int> &dp) {
        if(mask == (1LL << n) - 1) return 0;  

        if(dp[mask] != -1) {
            return dp[mask];
        }  

        // __builtin_popcount(mask) returns the total number of set bits in mask, which represents the current position in the ordering.
        int count = __builtin_popcount(mask) + 1;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            // If the current node has not been visited and its indegree is 0 (following Kahn's Algorithm for Topological Sort), 
            // We then decrease the indegree of each of its child nodes by one.
            if(!(1 & (mask >> i)) && indegree[i] == 0) {
                int newMask = mask | (1LL << i);
                
                for(auto &child: graph[i]) {
                    indegree[child]--;
                }
                
                ans = max(ans, count * score[i] + recursion(newMask, n, indegree, graph, score, dp));

                // Using backtracking and again incrementing the indegree of each of its child nodes by one.
                for(auto &child: graph[i]) {
                    indegree[child]++;
                }
            }
        }

        return dp[mask] = ans;
    }
    
    int maxProfit(int n, vector<vector<int>> &edges, vector<int> &score) {
        int m = edges.size();
        
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for(int i = 0; i < m; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        vector<int> dp((1LL << n), -1);
        return recursion(0, n, indegree, graph, score, dp);
    }
};