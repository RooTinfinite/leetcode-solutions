class Solution {
public:
    vector<int> parent, sz;
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 != r2) {
            if (sz[r1] < sz[r2]) swap(r1, r2);
            parent[r2] = r1;
            sz[r1] += sz[r2];
        }
    }

    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n); sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        
        unordered_map<int, int> xmap, ymap;
        for (int i = 0; i < n; i++) {
            if (xmap.count(points[i][0])) unite(i, xmap[points[i][0]]);
            else xmap[points[i][0]] = i;
            if (ymap.count(points[i][1])) unite(i, ymap[points[i][1]]);
            else ymap[points[i][1]] = i;
        }

        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                if (sz[i] > m1) { m2 = m1; m1 = sz[i]; }
                else if (sz[i] > m2) { m2 = sz[i]; }
            }
        }
        return m1 + m2 + 1;
    }
};