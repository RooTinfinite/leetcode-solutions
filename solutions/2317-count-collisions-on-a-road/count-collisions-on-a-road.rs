impl Solution {
    pub fn count_collisions(directions: String) -> i32 {
        let mut res = 0;
        let mut flag: i32 = -1;

        for c in directions.chars() {
            match c {
                'L' => {
                    if flag >= 0 {
                        res += flag + 1;
                        flag = 0;
                    }
                }
                'S' => {
                    if flag > 0 {
                        res += flag;
                    }
                    flag = 0;
                }
                'R' => {
                    if flag >= 0 {
                        flag += 1;
                    } else {
                        flag = 1;
                    }
                }
                _ => {}
            }
        }

        res
    }
}