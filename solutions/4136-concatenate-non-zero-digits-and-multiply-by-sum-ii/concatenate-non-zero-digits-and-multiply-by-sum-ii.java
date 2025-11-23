class Solution {
    static final long MOD = 1_000_000_007;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();
        int q = queries.length;
        int[] nonZeroCount = new int[n + 1];
        long[] prefixValue = new long[n + 1];
        long[] prefixDigitSum = new long[n + 1];
        long[] pow10 = new long[n + 1];

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int digit = s.charAt(i) - '0';

            nonZeroCount[i + 1] = nonZeroCount[i];
            prefixValue[i + 1] = prefixValue[i];
            prefixDigitSum[i + 1] = prefixDigitSum[i];

            if (digit != 0) {
                nonZeroCount[i + 1]++;
                prefixValue[i + 1] = (prefixValue[i] * 10 + digit) % MOD;
                prefixDigitSum[i + 1] += digit;
            }
        }

        int[] ans = new int[q];

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int count = nonZeroCount[r + 1] - nonZeroCount[l];
            long digitSum = prefixDigitSum[r + 1] - prefixDigitSum[l];

            long x;
            if (count == 0) {
                x = 0;
            } else {
                long leftContribution = (prefixValue[l] * pow10[count]) % MOD;
                x = (prefixValue[r + 1] - leftContribution + MOD) % MOD;
            }

            long result = (x * digitSum) % MOD;
            ans[i] = (int) result;
        }

        return ans;
    }
}