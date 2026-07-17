impl Solution {
    pub fn gcd_values(nums: Vec<i32>, queries: Vec<i64>) -> Vec<i32> {
        let m = *nums.iter().max().unwrap() as usize;
        let mut cnt = vec![0i64; m + 1];
        for &num in &nums {
            cnt[num as usize] += 1;
        }
        for i in 1..=m {
            let mut j = i * 2;
            while j <= m {
                cnt[i] += cnt[j];
                j += i;
            }
        }
        for i in 1..=m {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
        for i in (1..=m).rev() {
            let mut j = i * 2;
            while j <= m {
                cnt[i] -= cnt[j];
                j += i;
            }
        }
        for i in 1..=m {
            cnt[i] += cnt[i - 1];
        }
        let mut ans = Vec::new();
        for &q in &queries {
            let q = (q + 1) as i64;
            let pos = cnt.partition_point(|&x| x < q);
            ans.push(pos as i32);
        }
        ans
    }
}