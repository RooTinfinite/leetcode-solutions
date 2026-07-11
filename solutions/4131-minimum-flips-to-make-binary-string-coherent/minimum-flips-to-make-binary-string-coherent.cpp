class Solution {
public:
    int minFlips(string s) {
        int f[2] = {0, 0};
        for (auto &c : s)
            f[c & 1]++;

        if (!f[0] || !f[1]) return 0;

        return min(
            f[0],
            f[1] - (s.front() & s.back() & 1) - 1 //f[1] - (1 or 2)
        );
    }
};