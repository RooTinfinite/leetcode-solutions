impl Solution {
    fn reverse(mut n: i32) -> i32 {
        let mut res = 0;
        while n > 0 {
            res = res * 10 + n % 10;
            n /= 10;
        }
        res
    }

    fn mirror_distance(n: i32) -> i32 {
        (n - Self::reverse(n)).abs()
    }
}