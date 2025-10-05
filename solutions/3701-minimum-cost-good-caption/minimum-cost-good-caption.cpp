// By @Hack_Others
class Solution {
public:
    string minCostGoodCaption(string caption) {
        int n = caption.size();
        if (n < 3) {
            return "";
        }
        vector<array<int, 26>> dp(n);
        vector<int> maxDp(n);
        vector<int> maxPos(n);
        vector<array<int, 26>> step(n);
        for (int j = 0; j < 26; j++) {
            step[n - 3][j] = 3;
            for (int k = n - 3; k < n; k++) {
                dp[n - 3][j] += abs(caption[k] - 'a' - j);
            }
        }
        maxDp[n - 3] = dp[n - 3][0];
        for (int j = 1; j < 26; j++) {
            if (dp[n - 3][j] < maxDp[n - 3]) {
                maxDp[n - 3] = dp[n - 3][j];
                maxPos[n - 3] = j;
            }
        }
        for (int i = n - 4; i > -1; i--) {
            for (int j = 0; j < 26; j++) {
                // remain
                step[i][j] = 1;
                dp[i][j] = dp[i + 1][j] + abs(caption[i] - 'a' - j);
                // change
                if (i < n - 5) {
                    int newDp = maxDp[i + 3];
                    int newPos = maxPos[i + 3];
                    for (int k = i; k < i + 3; k++) {
                        newDp += abs(caption[k] - 'a' - j);
                    }
                    if (newDp < dp[i][j] || newDp == dp[i][j] && newPos < j) {
                        step[i][j] = 3;
                        dp[i][j] = newDp;
                    }
                }
            }
            maxDp[i] = dp[i][0];
            for (int j = 1; j < 26; j++) {
                if (dp[i][j] < maxDp[i]) {
                    maxDp[i] = dp[i][j];
                    maxPos[i] = j;
                }
            }
        }
        string res;
        int cur = 0;
        int curPos = maxPos[0];
        while (cur < n) {
            if (step[cur][curPos] == 1) {
                res += curPos + 'a';
                cur++;
                continue;
            }
            res.append(3, curPos + 'a');
            cur += 3;
            if (cur < n) {
                curPos = maxPos[cur];
            }
        }
        return res;
    }
};