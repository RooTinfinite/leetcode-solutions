impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let mut ans: Vec<i32> = Vec::new();
        let mut d = 0;
        for c in seq.chars() {
            if c == '(' {
                d += 1;
                ans.push(d % 2);
            }
            if c == ')' {
                ans.push(d % 2);
                d -= 1;
            }
        }
        ans
    }
}