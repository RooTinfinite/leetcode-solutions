class Solution {
public:
    typedef long long ll;
    pair<ll, ll> dfs(vector<vector<int>> &tree, vector<int>& values, int node, int parent){
        ll leftout = 0, taken = 0;
        for(auto c : tree[node]){
            if(c == parent) continue;
            auto [t, l] = dfs(tree, values, c, node);
            taken += t; leftout += l;
        }
        taken += (leftout != 0)?max(leftout, (ll)values[node]): 0;         //leftout 0 means its a leaf node and so we need to leave current nodeonly
        leftout = (leftout != 0)?min(leftout, (ll)values[node]): values[node];  
        //cout<<"node : "<<node<< " => "<<"taken : " <<taken<<", "<<"leftout : "<<leftout<<endl;  //Uncomment this line to see how the taken and leftout are changing 
        return {taken, leftout};
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> tree(values.size());
        for(auto e: edges){                  //create a grph from the edgegs given
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        return dfs(tree, values, 0, -1).first;
    }
};