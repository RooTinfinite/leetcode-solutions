impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let mut insertions = 0;
        let mut left_count = 0;
        let length = s.len();
        let chars: Vec<char> = s.chars().collect();
        let mut index = 0;

        while index < length {
            let c = chars[index];
            if c == '(' {
                left_count += 1;
                index += 1;
            } else {
                if left_count > 0 {
                    left_count -= 1;
                } else {
                    insertions += 1;
                }

                if index < length - 1 && chars[index + 1] == ')' {
                    index += 2;
                } else {
                    insertions += 1;
                    index += 1;
                }
            }
        }

        insertions += left_count * 2;
        insertions
    }
}