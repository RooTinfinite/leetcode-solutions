impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        let mut pre = vec![-1; n + 1];
        for i in 0..n {
            if i == 0 || chars[i - 1] == '0' {
                pre[i + 1] = i as i32;
            } else {
                pre[i + 1] = pre[i];
            }
        }

        let mut res = 0i32;
        for i in 1..=n {
            let mut cnt0 = if chars[i - 1] == '0' { 1 } else { 0 };
            let mut j = i as i32;
            while j > 0 && (cnt0 * cnt0) as usize <= n {
                let cnt1 = (i as i32 - pre[j as usize]) - cnt0;
                if cnt0 * cnt0 <= cnt1 {
                    res += std::cmp::min(j - pre[j as usize], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j as usize];
                cnt0 += 1;
            }
        }
        res
    }
}