func totalWaviness(num1 int, num2 int) int {
    // calculate the sum of the volatility values of all numbers in the range [0, num]
    solve := func(num int64) int64 {
        // if the number is less than 3, the fluctuation value is 0
        if num < 100 {
            return 0
        }
        s := fmt.Sprintf("%d", num)
        n := len(s)
        
        // memoized search uses two independent arrays
        // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
        memo_cnt := make([][][]int64, 16)
        // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
        memo_sum := make([][][]int64, 16)
        for i := 0; i < 16; i++ {
            memo_cnt[i] = make([][]int64, 10)
            memo_sum[i] = make([][]int64, 10)
            for j := 0; j < 10; j++ {
                memo_cnt[i][j] = make([]int64, 10)
                memo_sum[i][j] = make([]int64, 10)
                for k := 0; k < 10; k++ {
                    memo_cnt[i][j][k] = -1
                    memo_sum[i][j][k] = -1
                }
            }
        }
        
        var dfs func(pos int, prev int, curr int, isLimit bool, isLeading bool) (int64, int64)
        dfs = func(pos int, prev int, curr int, isLimit bool, isLeading bool) (int64, int64) {
            // end position
            if pos == n {
                return 1, 0
            }
            // only use memoization when not limited by an upper bound and not containing leading zeros
            if !isLimit && !isLeading && prev >= 0 && curr >= 0 {
                if memo_cnt[pos][prev][curr] != -1 {
                    return memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]
                }
            }
            
            // calculate the number of solutions and volatility value under current conditions
            var cnt, sum int64 = 0, 0
            up := 9
            if isLimit {
                up = int(s[pos] - '0')
            }
            for digit := 0; digit <= up; digit++ {
                newLeading := isLeading && (digit == 0)
                // the previous number is updated to curr
                newPrev := curr
                // the current number is updated to digit
                newCurr := digit
                if newLeading {
                    newCurr = -1
                }
                subCnt, subSum := dfs(pos+1, newPrev, newCurr, isLimit && (digit == up), newLeading)
                // only calculate the volatility value when there are no leading zeros
                if !newLeading && prev >= 0 && curr >= 0 {
                    // when the value is a peak or a trough, update the current fluctuation value
                    if (prev < curr && curr > digit) || (prev > curr && curr < digit) {
                        sum += subCnt
                    }
                }
                
                cnt += subCnt
                sum += subSum
            }
            
            if !isLimit && !isLeading && prev >= 0 && curr >= 0 {
                // update the memoization array
                memo_cnt[pos][prev][curr] = cnt
                memo_sum[pos][prev][curr] = sum
            }
            
            return cnt, sum
        }
        
        _, totalSum := dfs(0, -1, -1, true, true)
        return totalSum
    }
    
    return int(solve(int64(num2)) - solve(int64(num1-1)))
}