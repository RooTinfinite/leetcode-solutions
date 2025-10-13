class DSU {
public:
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];  // path compression
            x = parent[x];
        }
        return x;
    }

    void union_set(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 0, ans = -1;
        for (auto& e : edges) hi = max(hi, e[2]);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canSplit(n, edges, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    bool canSplit(int n, vector<vector<int>>& edges, int k, int maxTime) {
        DSU dsu(n);
        for (auto& e : edges) {
            if (e[2] > maxTime)
                dsu.union_set(e[0], e[1]);
        }
        return dsu.components >= k;
    }
};