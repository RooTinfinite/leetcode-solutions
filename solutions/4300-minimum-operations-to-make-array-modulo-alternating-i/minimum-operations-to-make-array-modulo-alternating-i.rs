impl Solution {
    fn helper(arr: &[i32], k: i32) -> [(i32, i32); 2] {
        let mut data:Vec<(i32, i32)> = vec!();

        for i in 0..k {
            let mut res = 0;
            for j in arr.iter() {
                let d = (i - *j).abs();
                res += d.min(k - d);
            }
            data.push((res, i));
        }

        data.sort();
        data[0..2].try_into().unwrap()

    }

    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        if nums.len() == 1 { return 0;}
        let mut even: Vec<i32> = vec!();
        let mut odd: Vec<i32> = vec!();
        for (i, val) in nums.into_iter().enumerate() {
            if i % 2 == 0 {
                even.push(val % k);
            } else {
                odd.push(val % k);
            }
        }

        let even_res = Self::helper(&even, k);
        let odd_res = Self::helper(&odd, k);

        if even_res[0].1 != odd_res[0].1 {
            even_res[0].0 + odd_res[0].0
        } else {
            let res1 = even_res[0].0 + odd_res[1].0;
            let res2 = even_res[1].0 + odd_res[0].0;
            res1.min(res2)
        }
    }
}