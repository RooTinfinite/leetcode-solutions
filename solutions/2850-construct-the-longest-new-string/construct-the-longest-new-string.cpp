class Solution {
public:
    int longestString(int x, int y, int z) {
        return 2 * (2 * min(x, y) + z + (x != y));
    }
};