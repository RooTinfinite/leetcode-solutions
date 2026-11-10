impl Solution {
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32 {
        let (mut a, mut b, mut c) = (0, 0, 0);
        for i in 0..n as usize {
            let nxt = (a + 9).min(b + 4).min(c + 1) + costs[i];
            a = b;
            b = c;
            c = nxt;
        }
        c
    }
}