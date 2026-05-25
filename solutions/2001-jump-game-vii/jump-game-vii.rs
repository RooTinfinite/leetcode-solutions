impl Solution {
    pub fn can_reach(s: String, min_jump: i32, max_jump: i32) -> bool {
        let n = s.len();
        let min_jump = min_jump as usize;
        let max_jump = max_jump as usize;
        let mut f = vec![0; n];
        let mut pre = vec![0; n];
        f[0] = 1;
        // since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
        for i in 0..min_jump {
            pre[i] = 1;
        }
        let s_chars: Vec<char> = s.chars().collect();
        for i in min_jump..n {
            let left = i as i32 - max_jump as i32;
            let right = i - min_jump;
            if s_chars[i] == '0' {
                let total = if left <= 0 {
                    pre[right]
                } else {
                    pre[right] - pre[left as usize - 1]
                };
                f[i] = if total != 0 { 1 } else { 0 };
            }
            pre[i] = pre[i - 1] + f[i];
        }
        f[n - 1] == 1
    }
}