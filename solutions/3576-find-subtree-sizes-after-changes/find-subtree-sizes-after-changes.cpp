class Solution {
public:
    // we're storing the occurences of each char in a vec //
    // size: (26,_) - one vec for each char seen so far
    vector<vector<int>> state;  

    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> subtreeSizes;
    
    void dfs(int node, string& s) {
        vis[node]=true;
        subtreeSizes[node] = 1; 

        state[s[node]-'a'].push_back(node);
        for(auto v: adj[node]) {
            if(!vis[v]) {
                dfs(v, s);
                /** above dfs will calculate subtree size rooted at v, now the imp part is which ancestor to add this zie to?? */
                
                // if s[v]-'a' has a matching, add to matched node
                int ind = s[v]-'a';
                if(state[ind].empty()) subtreeSizes[node] += subtreeSizes[v]; 
                else subtreeSizes[state[ind].back()] += subtreeSizes[v]; 
            }
        }
        state[s[node]-'a'].pop_back();     // backtrack
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n); 
        for(int i=1; i<n; i++) {
            adj[parent[i]].push_back(i);
        }

        state.resize(26);
        vis.assign(n, false);
        subtreeSizes.resize(n, 0);
        dfs(0, s);
        return subtreeSizes;
    }
};