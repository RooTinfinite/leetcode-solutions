impl Solution {
    pub fn first_uniq_char(input_str: String) -> i32 {
        let mut first_unique = i32::MAX;
        
        for c in 'a'..='z' {
            if input_str.contains(c) {
                if input_str.find(c) == input_str.rfind(c) {
                    first_unique = first_unique.min(input_str.find(c).unwrap() as i32);
                }
            }
        }
        
        if first_unique == i32::MAX { -1 } else { first_unique }
    }
}