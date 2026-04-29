class Solution {
public:
    /*
    1. no loop is reachable from source
    2. all paths end at destination
    3. there must exist one path to destination
    4. destination must be a leaf node (no outgoing edges)
    */
        bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
        }
        if(g[destination].size() != 0) //4
            return false;
        enum State {NotVisited, Visited, OnPath};
        vector<State> visited(n);
        stack<int> s;
        s.push(source);
        while(!s.empty()) {
            int v = s.top();
            if(visited[v] >= Visited) {
                visited[v] = Visited;
                s.pop();
            } else {
                visited[v] = OnPath;
                if(g[v].size() == 0 && v != destination) {
                    return false; //2
                }
                for(auto u: g[v]) {
                    if(visited[u] == OnPath)
                        return false; // 1
                    s.push(u);
                }
            }
            
        }
        return visited[destination]; //3
    }
};