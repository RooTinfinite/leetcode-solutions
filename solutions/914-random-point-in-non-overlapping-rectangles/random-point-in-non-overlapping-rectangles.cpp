class Solution {
public:
    Solution(std::vector<std::vector<int>>& rects)
        : rects(rects), x(rects[0][0] - 1), y(rects[0][1]), i(0) {}

    std::vector<int> pick() {
        // Increment x until reaching the right boundary of the current rectangle
        if (x != rects[i][2]) {
            ++x;
        }
        // If x reaches the right boundary, reset x to the left boundary and increment y
        else if (x == rects[i][2] && y != rects[i][3]) {
            x = rects[i][0];
            ++y;
        }
        // If both x and y reach the boundaries, move to the next rectangle
        else if (x == rects[i][2] && y == rects[i][3]) {
            i = (i < rects.size() - 1) ? i + 1 : 0;
            x = rects[i][0];
            y = rects[i][1];
        }
        return {x, y};
    }

private:
    std::vector<std::vector<int>> rects;
    int x, y, i; // x, y represent the current point, i represents the current rectangle index
};