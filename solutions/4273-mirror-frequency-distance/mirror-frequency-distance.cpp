class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> f1(10), f2(26);

        for (char &ch: s) {
            if (ch <= '9' && ch >= '0') {
                f1[ch-'0']++;
            } else {
                f2[ch-'a']++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += abs(f1[i] - f1[9 - i]);
        }

        for (int i = 0; i < 13; i++) {
            ans += abs(f2[i] - f2[25 - i]);
        }

        return ans;
    }
};