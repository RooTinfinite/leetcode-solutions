impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let (mut mx, mut mn) = (b'a', b'z');
        let mut sorted = true;
        for i in 0..n {
            mx = mx.max(s[i]);
            mn = mn.min(s[i]);
            if i > 0 && s[i - 1] > s[i] {
                sorted = false;
            }
        }
        if sorted {
            return 0;
        }
        if n == 2 {
            return -1;
        }
        if s[0] == mn || s[n - 1] == mx {
            return 1;
        }
        for i in 1..n - 1 {
            if s[i] == mn || s[i] == mx {
                return 2;
            }
        }
        3
    }
}