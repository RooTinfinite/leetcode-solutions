impl Solution {
    pub fn total_numbers(digits: Vec<i32>) -> i32 {
        let n = digits.len();
        let mut vis = [false; 1000];
        let mut ans = 0;

        for i in 0..n {
            if digits[i] == 0 {
                continue;
            }
            for j in 0..n {
                if j == i {
                    continue;
                }
                for k in 0..n {
                    if k == i || k == j || digits[k] % 2 != 0 {
                        continue;
                    }
                    let x = (digits[i] * 100 + digits[j] * 10 + digits[k]) as usize;
                    if !vis[x] {
                        vis[x] = true;
                        ans += 1;
                    }
                }
            }
        }

        ans
    }
}