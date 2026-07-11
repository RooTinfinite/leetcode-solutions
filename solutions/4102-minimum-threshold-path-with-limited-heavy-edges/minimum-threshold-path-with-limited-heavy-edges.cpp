class Solution {

    vector<vector<int>> edges;
    int source;
    int target;
    int k;
    int n;
    vector<vector<vector<int>>> adj;

    bool check(int mid) {

        vector<int> dist(n, 1e9);
        dist[source] = 0;
        // 0-1 BFS uses a deque
        deque<int> dq;
        dq.push_back(source);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for (auto &e : adj[u]) {
                int v = e[0];
                // check heavy or light according to threshold
                // light: 0 and heavy: 1
                int len = (e[1] > mid ? 1 : 0);
                if (dist[u] + len < dist[v]) {
                    dist[v] = dist[u] + len;
                    // front the deque as this would be the lowest distance till now
                    if (len == 0)
                        dq.push_front(v);
                    else
                        dq.push_back(v);
                }
            }
        }

        // check if we can reach by using atmost k heavy edges
        return dist[target] <= k;
    }
    
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        int low = 0;
        int high = 1e9 + 1;

        this->n = n;
        this->edges = edges;
        this->source = source;
        this->target = target;
        this->k = k;

        adj = vector<vector<vector<int>>> (n);

        // build the graph from edges
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int len = e[2];
            adj[u].push_back({v, len});
            adj[v].push_back({u, len});
        }

        // check for each threshold
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                // if possible, find better(lower threshold)
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};