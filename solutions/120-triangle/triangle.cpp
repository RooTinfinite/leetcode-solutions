class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = 1; row < triangle.size(); row++) {
            for (int col = 0; col <= row; col++) {
                int smallestAbove = INT_MAX;
                if (col > 0) {
                    smallestAbove = triangle[row - 1][col - 1];
                }
                if (col < row) {
                    smallestAbove = min(smallestAbove, triangle[row - 1][col]);
                }
                triangle[row][col] += smallestAbove;
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};