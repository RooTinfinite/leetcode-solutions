impl Solution {
    pub fn min_sum_of_lengths(mut arr: Vec<i32>, target: i32) -> i32 {
        let n = arr.len();
        let mut pos = std::collections::HashMap::new();
        pos.insert(0, -1i32);
        let (mut s, mut ans, mut min_l) = (0, (n + 1) as i32, n as i32);
        for i in 0..n {
            s += arr[i];
            if let Some(&j) = pos.get(&(s - target)) {
                let len = i as i32 - j;
                ans = ans.min(len + if j == -1 { n as i32 } else { arr[j as usize] });
                min_l = min_l.min(len);
            }
            arr[i] = min_l;
            pos.insert(s, i as i32);
        }
        if ans == (n + 1) as i32 { -1 } else { ans }
    }
}