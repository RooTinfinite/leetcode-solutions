impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        let n = colors.len();
        let mut res = 0;   // the maximum distance between two houses of different colors
        // traverse the indices of two houses and maintain the maximum distance
        for i in 0..n {
            for j in i + 1..n {
                if colors[i] != colors[j] {
                    res = res.max((j as i32) - (i as i32));
                }
            }
        }
        res
    }
}