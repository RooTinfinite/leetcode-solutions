impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let change = |x: i32, y: i32| -> String {
            num.to_string()
                .chars()
                .map(|digit| if digit.to_digit(10).unwrap() as i32 == x { (y as u8 + b'0') as char } else { digit })
                .collect()
        };

        let mut min_num = num;
        let mut max_num = num;

        for x in 0..10 {
            for y in 0..10 {
                let res = change(x, y);
                 // Check if there are leading zeros
                if res.chars().nth(0).unwrap() != '0' {
                    let res_i: i32 = res.parse().unwrap();
                    min_num = min_num.min(res_i);
                    max_num = max_num.max(res_i);
                }
            }
        }

        max_num - min_num
    }
}