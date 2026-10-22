impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return 0;
        }

        let start = nums.iter().position(|&x| x == 0).unwrap();

        let mut asc = true;
        let mut desc = true;

        for i in 1..n {
            let value = nums[(start + i) % n];

            if value != i as i32 {
                asc = false;
            }
            if value != (n - i) as i32 {
                desc = false;
            }

            if !asc && !desc {
                return -1;
            }
        }

        if asc {
            return start.min(n - start + 2) as i32;
        }

        (n - start).min(start + 2) as i32
    }
}