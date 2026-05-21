use std::collections::HashSet;

impl Solution {
    pub fn longest_common_prefix(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {

        let mut st1 = HashSet::new();
        let mut st2 = HashSet::new();

        for mut num in arr1 {

            while num > 0 {
                st1.insert(num);
                num /= 10;
            }
        }

        for mut num in arr2 {

            while num > 0 {
                st2.insert(num);
                num /= 10;
            }
        }

        let mut ans = 0;

        for &x in st1.iter() {

            if st2.contains(&x) {

                let mut num = x;
                let mut cnt = 0;

                while num > 0 {
                    cnt += 1;
                    num /= 10;
                }

                ans = ans.max(cnt);
            }
        }

        ans
    }
}