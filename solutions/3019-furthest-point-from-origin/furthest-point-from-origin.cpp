class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int n = moves.length();
        for (char c : moves) {
            if (c == 'L') {
                l++;
            } else if (c == 'R') {
                r++;
            }
        }
        return (l > r) ? n - 2 * r : n - 2 * l;
    }
};