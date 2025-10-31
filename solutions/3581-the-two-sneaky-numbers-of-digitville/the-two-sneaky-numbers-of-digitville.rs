impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        let mut count = std::collections::HashMap::new();
        for x in nums {
            let c = count.entry(x).or_insert(0);
            *c += 1;
            if *c == 2 {
                res.push(x);
            }
        }
        res
    }
}