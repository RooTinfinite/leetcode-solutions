class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < preferences[i].size(); ++j) {
                rank[i][preferences[i][j]] = j;
            }
        }
        vector<int> pairedWith(n);
        for (auto& pair : pairs) {
            pairedWith[pair[0]] = pair[1];
            pairedWith[pair[1]] = pair[0];
        }
        int unhappyCount = 0;
        for (int x = 0; x < n; ++x) {
            int y = pairedWith[x];
            for (int i = 0; i < rank[x][y]; ++i) {
                int u = preferences[x][i];
                int v = pairedWith[u];
                if (rank[u][x] < rank[u][v]) {
                    ++unhappyCount;
                    break;
                }
            }
        }
        return unhappyCount;
    }
};