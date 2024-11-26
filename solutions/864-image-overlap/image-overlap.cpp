class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<unsigned int> small1(n, 0);
        vector<unsigned int> small2(n, 0);
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                small1[row] |= img1[row][col] << col;
                small2[row] |= img2[row][col] << col;
            }
        }
        int maxOverlap = 0;
        for(int upMove = -n + 1; upMove < n; ++upMove) {
            for(int sideMove = 0; sideMove < n; ++sideMove) {
                int overlapL = 0, overlapR = 0;
                for(int row = 0; row + abs(upMove) < n; ++row) {
                    int row1 = upMove < 0 ? row - upMove : row;
                    int row2 = upMove < 0 ? row : row + upMove;
                    overlapL += __builtin_popcount((small1[row1] << sideMove) & small2[row2]);
                    overlapR += __builtin_popcount((small1[row1] >> sideMove) & small2[row2]);
                }
                maxOverlap = max(maxOverlap, max(overlapL, overlapR));
            }
        }
        return maxOverlap;
    }
};