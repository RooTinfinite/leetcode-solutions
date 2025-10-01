class Solution {
public:
set<int> se;
void dfs(int method, vector<vector<int>>& invocations, vector<bool>& visited, vector<bool>& suspicious) {
    visited[method] = true;
    suspicious[method] = true; 
    se.insert(method);
    for (int invokedMethod : invocations[method]) {
        if (!visited[invokedMethod]) {
            dfs(invokedMethod, invocations, visited, suspicious);
        }
    }
}

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
      vector<vector<int>> graph(n);  
    vector<bool> suspicious(n, false);  
    vector<bool> visited(n, false);     


    for (auto& x : invocations) {
        int a = x[0];
        int b = x[1];
        graph[a].push_back(b); 
    }

    dfs(k, graph, visited, suspicious);

    vector<int> ans;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (suspicious[i] == false) {
           for(int x : graph[i]){
            if(suspicious[x]){
                vector<int> all;
                for(int i=0; i<n; i++){
                    all.push_back(i);
                }
                return all;
            }
           }
        }
    }
 for (int i = 0; i < n; i++) {
        if (suspicious[i] == false) {
           ans.push_back(i);
           }
    }

    return ans;
    }
};