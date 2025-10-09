// Problem: Assign Edge Weights in Tree Path to Max Depth Node with Odd Total Cost
// Given a tree rooted at node 1, find the number of ways to assign weights (1 or 2) 
// to edges along the path from node 1 to the deepest node such that the sum of weights is odd.
// Return the count modulo 10^9+7.

// Explanation:
// - Perform DFS to find maximum depth 'm' from the root (node 1).
// - The longest path from root to deepest node has 'm' edges.
// - Each edge weight can be 1 or 2, so total assignments = 2^m.
// - Odd sum of weights occurs when number of edges with weight 1 is odd.
// - Exactly half of assignments produce odd sums, so answer = 2^(m-1).
// - If max depth m=0 (only root), no edges exist, so answer = 0.

// Time Complexity: O(N) due to DFS traversal of all nodes.
// Space Complexity: O(N) for adjacency list and recursion stack.

class Solution{
public:
    static const int MOD=1e9+7;
    int assignEdgeWeights(vector<vector<int>>&edges){
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto&i:edges){
            int j=i[0],k=i[1];
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        vector<int>depth(n+1,-1);
        dfs(1,0,0,adj,depth);
        int m=0;
        for(auto x:depth) m=max(m,x);
        if(m==0) return 0;
        return modPow(2,m-1);
    }
    void dfs(int u,int p,int h,vector<vector<int>>&adj,vector<int>&depth){
        depth[u]=h;
        for(auto&v:adj[u]){
            if(v!=p) dfs(v,u,h+1,adj,depth);
        }
    }
    int modPow(long long b,int e){
        long long r=1;
        b%=MOD;
        while(e>0){
            if(e&1) r=(r*b)%MOD;
            b=(b*b)%MOD;
            e>>=1;
        }
        return (int)r;
    }
};
