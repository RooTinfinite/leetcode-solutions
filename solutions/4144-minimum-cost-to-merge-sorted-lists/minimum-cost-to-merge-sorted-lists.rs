impl Solution {
    fn num_lt(lists: &Vec<Vec<i32>>, enabled: usize, guess: i32) -> usize {
        let mut result = 0;
        for i in 0..lists.len() {
            if (enabled >> i) & 1 == 1 {
                // so we're looking for the first thing >= guess
                let num_lt = lists[i].partition_point(|v| *v < guess);
                result += num_lt;
            }
        }
        result
    }
    pub fn min_merge_cost(lists: Vec<Vec<i32>>) -> i64 {
        let n = lists.len();
        let mut all_nums = Vec::new();
        for lst in lists.iter() {
            all_nums.append(&mut lst.clone());
        }
        all_nums.sort();
        // first, we precompute median and length for all subsets
        // subsets[subset] = (length, median)
        let mut subsets = vec![(0, 0)];
        for subset in 1..1 << n {
            let result_len: usize = (0..lists.len())
                .map(|i| lists[i].len() * ((subset >> i) & 1))
                .sum();
            let median_lt = (result_len - 1) / 2;
            // then find the median
            // instead of spending linear time to merge the lists
            // we can binary search guess and check
            let mut low = 0;
            let mut high = all_nums.len() - 1;
            let mut actual_median = -1;
            while low <= high {
                let mid = (low + high) / 2;
                let num = all_nums[mid];
                let num_lt = Self::num_lt(&lists, subset, num);
                if num_lt <= median_lt {
                    // works; try guessing a bigger number
                    actual_median = num;
                    low = mid + 1;
                } else {
                    // guessed too high, try guessing smaller
                    high = mid - 1;
                }
            }
            subsets.push((result_len as i64, actual_median as i64));
        }
        // now we dp to figure out, for all subsets,
        // the minimum cost to make it
        let mut dp = vec![i64::MAX; 1 << n];
        for subset in 0..(1 << n) as usize {
            if subset.count_ones() <= 1 {
                // nothing to merge
                dp[subset] = 0;
            } else {
                // this subset S must come from merging some subset A of S   
                // with S - A
                let mut a = (subset - 1) & subset;
                while a > 0 {
                    // xor to get S-A
                    let b = subset ^ a;  
                    let a_info = subsets[a];
                    let b_info = subsets[b];
                    let cost = a_info.0 + b_info.0 + (a_info.1 - b_info.1).abs();
                    dp[subset] = dp[subset].min(dp[a] + dp[b] + cost);
                    a = (a - 1) & subset;  // advance to next subset
                }
            }
        }

        *dp.last().unwrap()
    }
}