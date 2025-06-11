impl Solution {
    pub fn max_difference(s: String, k: i32) -> i32 {
        let n = s.len();
        let mut ans = i32::MIN;
        let chars: Vec<char> = s.chars().collect();
        
        fn get_status(cnt_a: i32, cnt_b: i32) -> i32 {
            ((cnt_a & 1) << 1) | (cnt_b & 1)
        }
        
        for a in ['0', '1', '2', '3', '4', '5'] {
            for b in ['0', '1', '2', '3', '4', '5'] {
                if a == b { 
                    continue; 
                }
                
                let mut best = [i32::MAX; 4];
                let (mut cnt_a, mut cnt_b) = (0, 0);
                let (mut prev_a, mut prev_b) = (0, 0);
                let mut left = -1;
                
                for right in 0..n {
                    cnt_a += if chars[right] == a { 1 } else { 0 };
                    cnt_b += if chars[right] == b { 1 } else { 0 };
                    
                    while (right as i32 - left) >= k && (cnt_b - prev_b) >= 2 {
                        let left_status = get_status(prev_a, prev_b) as usize;
                        best[left_status] = best[left_status].min(prev_a - prev_b);
                        left += 1;
                        prev_a += if chars[left as usize] == a { 1 } else { 0 };
                        prev_b += if chars[left as usize] == b { 1 } else { 0 };
                    }
                    
                    let right_status = get_status(cnt_a, cnt_b) as usize;
                    if best[right_status ^ 0b10] != i32::MAX {
                        ans = ans.max(cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        ans
    }
}