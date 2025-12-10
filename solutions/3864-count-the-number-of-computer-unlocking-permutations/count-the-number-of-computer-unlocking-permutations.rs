impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let n = complexity.len();
        for i in 1..n {
            if complexity[i] <= complexity[0] {
                return 0;
            }
        }
        
        let mut ans: i64 = 1;
        let mod_val: i64 = 1_000_000_007;
        for i in 2..n {
            ans = (ans * i as i64) % mod_val;
        }
        ans as i32
    }
}