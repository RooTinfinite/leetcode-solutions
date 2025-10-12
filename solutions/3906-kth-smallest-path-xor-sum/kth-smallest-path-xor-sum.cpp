#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
        ordered_set* dfs(int node, int parent,vector<vector<int>>&tree,vector<int>& vals,vector<int>&xorPaths, vector<vector<pair<int, int>>> &query, vector<int>&ans ){

        if(node !=0){
            xorPaths[node] = xorPaths[parent] ^ vals[node];
        }

        ordered_set* currSet  = new ordered_set;

        currSet->insert(xorPaths[node]);

        for(auto &child: tree[node]){
            ordered_set* childSet = dfs(child,node,tree,vals,xorPaths,query,ans);
            if(childSet->size() > currSet->size()){
                swap(childSet,currSet);
            }
            for(auto &xorValues:*childSet){
                currSet->insert(xorValues);
            }
        }
        for(auto [k,idx]:query[node]){
            if(currSet->size() < k) ans[idx]=-1;
            else{
                int val = *currSet->find_by_order(k - 1);
                ans[idx] = val;
            }
        }
        return currSet;
    }
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        int n = par.size();
        vector<int>xorPaths(n);
        int q = queries.size();
        vector<int>ans(q);

        vector<vector<int>>tree(n);
        for(int i=1;i<n;i++){
            tree[par[i]].push_back(i);
        }

        vector<vector<pair<int, int>>> query(n);
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], k = queries[i][1];
            query[u].push_back({k, i});
        }

        xorPaths[0] = vals[0];

        dfs(0,-1,tree,vals,xorPaths,query,ans);
        return ans;
    }
};