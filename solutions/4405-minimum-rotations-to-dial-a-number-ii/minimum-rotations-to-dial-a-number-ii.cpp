class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b) { int d = (a - b + 10) % 10; return min(d, 10 - d); };
        int last = s.back() - '0', prev = 0, base = 0, gain = INT_MIN;
        for (char c : s) {
            int cur = c - '0';
            base += dist(prev, cur);
            gain = max(gain, dist(prev, cur) - dist(prev, last));  // cut before cur
            prev = cur;
        }
        return base - gain;
    }
};