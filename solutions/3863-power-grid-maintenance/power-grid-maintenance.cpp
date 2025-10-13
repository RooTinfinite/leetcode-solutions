class Solution {
public:
    vector<int> parent;
    vector<set<int>> onlinenodes;
    vector<bool> isonline;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionset(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a != b) {
            if (onlinenodes[a].size() < onlinenodes[b].size()) {
                swap(a, b);
            }
            parent[b] = a;

            for (int n : onlinenodes[b]) {
                onlinenodes[a].insert(n);
            }
            onlinenodes[b].clear();
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        // using dsu as here is case of graph connectivity in same grids..

         parent.resize(c + 1);
        iota(parent.begin(), parent.end(), 0);
        
        onlinenodes.resize(c + 1);
        isonline.resize(c + 1, true);

        for (int i = 1; i <= c; ++i) {
            onlinenodes[i].insert(i);
        }

        for (auto& conn : connections) {
            unionset(conn[0], conn[1]);
        }

        vector<int> results;

        for (auto& query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 1) {
                if (isonline[x]) {
                    results.push_back(x);
                } else {
                    int rootX = find(x);
                    if (onlinenodes[rootX].empty()) {
                        results.push_back(-1);
                    } else {
                        results.push_back(*onlinenodes[rootX].begin());
                    }
                }
            } else {
                if (isonline[x]) {
                    isonline[x] = false;
                    int rootX = find(x);
                    onlinenodes[rootX].erase(x);
                }
            }
        }

        return results;
    }
};