impl Solution {
    pub fn stone_game_viii(stones: Vec<i32>) -> i32 {
        let n = stones.len();
        let mut pre = vec![0; n];
        pre[0] = stones[0];
        for i in 1..n {
            pre[i] = pre[i - 1] + stones[i];
        }
        
        let mut f = vec![0; n];
        f[n - 1] = pre[n - 1];
        for i in (1..n - 1).rev() {
            f[i] = f[i + 1].max(pre[i] - f[i + 1]);
        }
        f[1]
    }
}