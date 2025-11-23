class Solution {
public:
    static const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> prefixValue(n + 1, 0);
        vector<long long> prefixDigitSum(n + 1, 0);
        vector<long long> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            nonZeroCount[i + 1] = nonZeroCount[i];
            prefixValue[i + 1] = prefixValue[i];
            prefixDigitSum[i + 1] = prefixDigitSum[i];

            if (digit != 0) {
                nonZeroCount[i + 1]++;
                prefixValue[i + 1] = (prefixValue[i] * 10 + digit) % MOD;
                prefixDigitSum[i + 1] += digit;
            }
        }

        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int count = nonZeroCount[r + 1] - nonZeroCount[l];
            long long sum = prefixDigitSum[r + 1] - prefixDigitSum[l];

            long long x;
            if (count == 0) {
                x = 0;
            } else {
                long long left = (prefixValue[l] * pow10[count]) % MOD;
                x = (prefixValue[r + 1] - left + MOD) % MOD;
            }
            ans[i] = (x * sum) % MOD;
        }

        return ans;
    }
};