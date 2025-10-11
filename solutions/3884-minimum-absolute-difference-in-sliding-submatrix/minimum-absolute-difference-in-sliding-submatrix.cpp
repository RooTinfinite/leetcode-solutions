class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int m = grid.size() + 1, n = grid[0].size() + 1, sub = k * k;
        vector<vector<int>> res(m - k, vector<int>(n - k, 0));
        for(int i = k; i < m; ++i){
            for(int j = k; j < n; ++j){
                vector<int> temp(sub , 0);
                for(int x = i - k, l = 0; x < i; ++x){
                    for(int y = j - k; y < j; ++y, ++l) temp[l] = grid[x][y];
                }
                sort(temp.begin() , temp.end());
                int diff = INT_MAX;
                for(int l = 1; l < sub; ++l){
                    int a = temp[l - 1], b = temp[l];
                    diff = (a != b) ? min(diff , b - a) : diff;
                }
                res[i - k][j - k] = (diff == INT_MAX) ? 0 : diff;
            }
        }
        return res;
    }
};