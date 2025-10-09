class BinaryLiftingLCA {
    int n, LOG;
    vector<vector<pair<int, int>>> adj; 
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> distFromRoot;

public:
    BinaryLiftingLCA(int nodes) {
        n = nodes;
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        adj.resize(n);
        up.assign(n, vector<int>(LOG, -1));
        depth.resize(n);
        distFromRoot.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void build(int root = 0) {
        dfs(root, -1, 0, 0);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    long long distance(int u, int v) {
        int ancestor = lca(u, v);
        return distFromRoot[u] + distFromRoot[v] - 2 * distFromRoot[ancestor];
    }

private:
    void dfs(int v, int p, int d, long long dist) {
        depth[v] = d;
        distFromRoot[v] = dist;
        up[v][0] = p;

        for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
        }

        for (auto &[u, w] : adj[v]) {
            if (u != p) {
                dfs(u, v, d + 1, dist + w);
            }
        }
    }

    int lift(int v, int k) {
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                v = up[v][i];
                if (v == -1) break;
            }
        }
        return v;
    }
};


class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        BinaryLiftingLCA b1(n);
        for(auto it:edges){
            b1.addEdge(it[0],it[1],it[2]);
        }
        b1.build();
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int s1,s2,d1;
            s1 = queries[i][0];s2 = queries[i][1];d1 = queries[i][2];
            int db1 = b1.distance(s1,s2);
            int db2 = b1.distance(s1,d1);
            int db3 = b1.distance(s2,d1);
            ans.push_back((db1+db2+db3)/2);
        }
        return ans;
    }
};