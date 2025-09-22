class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n , vector<int>(n , 0));
        for(int i = 0, m = queries.size(); i < m; ++i){
            int r1 = queries[i][0], c1 = queries[i][1];
            int r2 = queries[i][2], c2 = queries[i][3];
            ++res[r1][c1];
            if(r2 + 1 < n && c2 + 1 < n) ++res[r2 + 1][c2 + 1];
            if(r2 + 1 < n) --res[r2 + 1][c1];
            if(c2 + 1 < n) --res[r1][c2 + 1];
        }
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < n; ++j) res[i][j] += res[i][j - 1];
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n; ++j) res[i][j] += res[i - 1][j];
        }
        return res;
    }
};