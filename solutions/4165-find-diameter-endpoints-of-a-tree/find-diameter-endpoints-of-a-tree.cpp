class Solution {
public:
    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        unordered_map<int,vector<int>> graph;

        for (int i = 0; i < m; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        string s = "";

        queue<pair<int,int>> q;
        unordered_set<int> visited;
        vector<int> dist(n,0);

        q.push({0,0});
        visited.insert(0);

        int mx_val = 0;

        while (!q.empty()){
            auto v = q.front();
            q.pop();

            dist[v.first] = v.second;
            mx_val = max(mx_val,dist[v.first]);

            for (int neighbor: graph[v.first]){
                if (!visited.contains(neighbor)){
                    q.push({neighbor,v.second+1});
                    visited.insert(neighbor);
                }
            }
        }

        unordered_set<int> special;

        int sp = -1;

        for (int i = 0; i < n; i++){
            if (dist[i] == mx_val){
                special.insert(i);
                sp = i;
            }
        }

        q;
        visited = {};
        dist;

        q.push({sp,0});
        visited.insert(sp);

        mx_val = 0;

        while (!q.empty()){
            auto v = q.front();
            q.pop();

            dist[v.first] = v.second;
            mx_val = max(mx_val,dist[v.first]);

            for (int neighbor: graph[v.first]){
                if (!visited.contains(neighbor)){
                    q.push({neighbor,v.second+1});
                    visited.insert(neighbor);
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (dist[i] == mx_val){
                special.insert(i);
            }
        }

        for (int i = 0; i < n; i++){
            if (special.contains(i)){
                s += "1";
            } else {
                s += "0";
            }
        }

        return s;
    }
};