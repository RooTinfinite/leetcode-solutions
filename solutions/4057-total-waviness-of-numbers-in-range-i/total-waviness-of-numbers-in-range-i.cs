public class Solution {
    private string s;
    private int n;
    private long[,,] memo_cnt;
    private long[,,] memo_sum;

    public int TotalWaviness(int num1, int num2) {
        return (int)(Solve(num2) - Solve(num1 - 1));
    }

    // calculate the sum of the volatility values of all numbers in the range
    // [0, num]
    private long Solve(long num) {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0L;
        }
        s = num.ToString();
        n = s.Length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the
        // current position is pos, and the previous two positions are x, y
        memo_cnt = new long[16, 10, 10];
        // memo_sum[pos][x][y]: the fluctuation value when the current position
        // is pos and the two left digits are x and y
        memo_sum = new long[16, 10, 10];
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    memo_cnt[i, j, k] = -1;
                    memo_sum[i, j, k] = -1;
                }
            }
        }

        long[] result = Dfs(0, -1, -1, true, true);
        return result[1];
    }

    private long[] Dfs(int pos, int prev, int curr, bool isLimit,
                       bool isLeading) {
        // end position
        if (pos == n) {
            return new long[] { 1L, 0L };
        }
        // only use memoization when not limited by an upper bound and not
        // containing leading zeros
        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            if (memo_cnt[pos, prev, curr] != -1) {
                return new long[] { memo_cnt[pos, prev, curr],
                                    memo_sum[pos, prev, curr] };
            }
        }

        // calculate the number of solutions and volatility value under current
        // conditions
        long cnt = 0, sum = 0;
        int up = isLimit ? (s[pos] - '0') : 9;
        for (int digit = 0; digit <= up; ++digit) {
            bool newLeading = isLeading && (digit == 0);
            // the previous number is updated to curr
            int newPrev = curr;
            // the current number is updated to digit
            int newCurr = newLeading ? -1 : digit;
            long[] sub = Dfs(pos + 1, newPrev, newCurr,
                             isLimit && (digit == up), newLeading);
            long subCnt = sub[0], subSum = sub[1];
            // only calculate the volatility value when there are no leading
            // zeros
            if (!newLeading && prev >= 0 && curr >= 0) {
                // when the value is a peak or a trough, update the current
                // fluctuation value
                if ((prev < curr && curr > digit) ||
                    (prev > curr && curr < digit)) {
                    sum += subCnt;
                }
            }

            cnt += subCnt;
            sum += subSum;
        }

        if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
            // update the memoization array
            memo_cnt[pos, prev, curr] = cnt;
            memo_sum[pos, prev, curr] = sum;
        }

        return new long[] { cnt, sum };
    }
}