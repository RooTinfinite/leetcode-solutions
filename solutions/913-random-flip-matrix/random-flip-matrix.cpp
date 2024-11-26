#include <vector>

class Solution {
    int row = 0, col = 0;
    int totalRows = 0, totalCols = 0;

public:
    Solution(int m, int n) : totalRows(m), totalCols(n) {}

    std::vector<int> flip() {
        col++;
        if (col == totalCols) {
            col = 0;
            row++;
        }
        if (row == totalRows) {
            row = 0;
            col = 0;
        }

        return {row, col};
    }

    void reset() {
        // Resetting is not necessary since it will automatically reset when reaching the end.
    }
};