impl Solution {
    pub fn can_change(start: String, target: String) -> bool {
        if start == target {
            return true;
        }
        let mut wait_l = 0;
        let mut wait_r = 0;
        
        let start_chars: Vec<char> = start.chars().collect();
        let target_chars: Vec<char> = target.chars().collect();
        
        for i in 0..start_chars.len() {
            let curr = start_chars[i];
            let goal = target_chars[i];
            
            if curr == 'R' {
                if wait_l > 0 {
                    return false;
                }
                wait_r += 1;
            }
            if goal == 'L' {
                if wait_r > 0 {
                    return false;
                }
                wait_l += 1;
            }
            if goal == 'R' {
                if wait_r == 0 {
                    return false;
                }
                wait_r -= 1;
            }
            if curr == 'L' {
                if wait_l == 0 {
                    return false;
                }
                wait_l -= 1;
            }
        }
        wait_l == 0 && wait_r == 0
    }
}