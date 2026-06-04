var totalWaviness = function (num1, num2) {
    // calculate the sum of fluctuation values of all numbers in [0, num]
    const solve = (num) => {
        // if the number is less than 3, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        const s = num.toString();
        const n = s.length;

        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        const memo_cnt = Array(16)
            .fill()
            .map(() =>
                Array(10)
                    .fill()
                    .map(() => Array(10).fill(-1)),
            );
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        const memo_sum = Array(16)
            .fill()
            .map(() =>
                Array(10)
                    .fill()
                    .map(() => Array(10).fill(-1)),
            );

        const dfs = (pos, prev, curr, isLimit, isLeading) => {
            // end position
            if (pos === n) {
                return [1, 0];
            }
            // only use memoization when not limited by an upper bound and not containing leading zeros
            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                if (memo_cnt[pos][prev][curr] !== -1) {
                    return [
                        memo_cnt[pos][prev][curr],
                        memo_sum[pos][prev][curr],
                    ];
                }
            }

            // calculate the number of solutions and volatility value under current conditions
            let cnt = 0,
                sum = 0;
            const up = isLimit ? parseInt(s[pos]) : 9;
            for (let digit = 0; digit <= up; ++digit) {
                const newLeading = isLeading && digit === 0;
                // the previous number is updated to curr
                const newPrev = curr;
                // the current number is updated to digit
                const newCurr = newLeading ? -1 : digit;
                const [subCnt, subSum] = dfs(
                    pos + 1,
                    newPrev,
                    newCurr,
                    isLimit && digit === up,
                    newLeading,
                );
                // only calculate the volatility value when there are no leading zeros
                if (!newLeading && prev >= 0 && curr >= 0) {
                    // when the value is a peak or a trough, update the current fluctuation value
                    if (
                        (prev < curr && curr > digit) ||
                        (prev > curr && curr < digit)
                    ) {
                        sum += subCnt;
                    }
                }

                cnt += subCnt;
                sum += subSum;
            }

            if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                // update the memoization array
                memo_cnt[pos][prev][curr] = cnt;
                memo_sum[pos][prev][curr] = sum;
            }

            return [cnt, sum];
        };

        const [_, totalSum] = dfs(0, -1, -1, true, true);
        return totalSum;
    };

    return solve(num2) - solve(num1 - 1);
};