class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        if (m < n) return false;

        int idx2 = 0;
        for (int idx1 = 0; idx1 < m && idx2 < n; idx1++) {
            if (str1[idx1] == str2[idx2] ||
                str1[idx1] + 1 == str2[idx2] ||
                str1[idx1] - 25 == str2[idx2]) {
                idx2++;
            }
        }

        return idx2 == n;
    }
};