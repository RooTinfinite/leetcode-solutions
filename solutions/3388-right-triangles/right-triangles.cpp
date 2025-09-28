class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& mat) {
        typedef long long LL;
        int r = mat.size(), c = mat[0].size();
        LL ans = 0;
        vector<int> row(r), col(c);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (!mat[i][j])
                    continue;
                ++row[i];
                ++col[j];
            }
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (!mat[i][j])
                    continue;
                ans += (row[i] - 1) * (col[j] - 1LL);
            }
        return ans;
    }
};