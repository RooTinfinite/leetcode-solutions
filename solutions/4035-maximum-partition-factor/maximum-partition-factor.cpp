class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 2) return 0;

        // Step 1: Build all (distance, i, j)
        vector<array<int, 3>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
                edges.push_back({d, i, j});
            }
        }

        // Step 2: Sort edges by distance
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        // Step 3: Union-Find initialization
        vector<int> parent(n), weight(n, 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> opp;

        // Step 4: Process edges
        for (auto& e : edges) {
            int d = e[0], i = e[1], j = e[2];

            if (findParent(i, parent) == findParent(j, parent))
                return d;

            if (opp.count(i))
                unite(opp[i], j, parent, weight);
            if (opp.count(j))
                unite(opp[j], i, parent, weight);

            opp[i] = j;
            opp[j] = i;
        }

        return edges.back()[0];
    }

private:
    int findParent(int a, vector<int>& parent) {
        if (parent[a] != a)
            parent[a] = findParent(parent[a], parent);
        return parent[a];
    }

    void unite(int x, int y, vector<int>& parent, vector<int>& weight) {
        x = findParent(x, parent);
        y = findParent(y, parent);
        if (x == y) return;

        if (weight[x] < weight[y])
            swap(x, y);

        weight[y] += weight[x];
        parent[x] = y;
    }
};