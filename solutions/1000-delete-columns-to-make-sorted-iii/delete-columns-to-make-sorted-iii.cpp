vector<int8_t> adj[100];
int deg[100];
int dp[100];

class Solution {
public:
    static int minDeletionSize(vector<string>& strs) {
        const int n=strs.size(), m=strs[0].size();

        for(int i=0; i<m; i++) adj[i].clear();
        memset(dp, -1, sizeof(int)*m);
        memset(deg, 0, sizeof(int)*m);

        // build adjacency list & indegree
        for (int j=0; j <m-1; j++) {
            for (int last=j+1; last<m; last++) {
                if (all_of(strs.begin(), strs.end(),
                           [&](const string& s) { return s[j]<=s[last];})) {
                    adj[j].push_back(last);
                    deg[last]++;
                }
            }
        }

        // Perform topological sort using BFS (Kahn's algorithm)
        queue<int8_t> q;
        for (int i=0; i<m; i++) {
            if (deg[i]==0) 
                q.push(i);
        }
        int d;
        for(d=0; !q.empty(); d++){
            int qz=q.size();
            for(int a=0; a<qz; a++) {
                int i=q.front();
                q.pop();
                for (int j : adj[i]) {
                    if (--deg[j]==0) 
                        q.push(j);
                }
            }
        }
        return m-d;
    }
};