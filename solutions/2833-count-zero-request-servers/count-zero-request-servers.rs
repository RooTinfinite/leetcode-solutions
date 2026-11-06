impl Solution {
    pub fn count_servers(n: i32, mut logs: Vec<Vec<i32>>, x: i32, queries: Vec<i32>) -> Vec<i32> {
        logs.sort_unstable_by_key(|log| log[1]);
        let mut ids: Vec<usize> = (0..queries.len()).collect();
        ids.sort_unstable_by_key(|&i| queries[i]);

        let mut ans = vec![0; queries.len()];
        let mut cnt = vec![0; n as usize + 1];
        let (mut left, mut right, mut active) = (0, 0, 0);

        for i in ids {
            let q = queries[i];
            while right < logs.len() && logs[right][1] <= q {
                let id = logs[right][0] as usize;
                if cnt[id] == 0 {
                    active += 1;
                }
                cnt[id] += 1;
                right += 1;
            }
            while left < right && logs[left][1] < q - x {
                let id = logs[left][0] as usize;
                cnt[id] -= 1;
                if cnt[id] == 0 {
                    active -= 1;
                }
                left += 1;
            }
            ans[i] = n - active;
        }
        ans
    }
}