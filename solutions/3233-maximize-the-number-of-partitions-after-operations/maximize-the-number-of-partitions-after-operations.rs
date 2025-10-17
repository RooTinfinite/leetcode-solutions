impl Solution {
    pub fn max_partitions_after_operations(s: String, k: i32) -> i32 {
        let n = s.len();
        let mut left = vec![[0; 3]; n];
        let mut right = vec![[0; 3]; n];
        let bytes = s.as_bytes();
        
        let (mut num, mut mask, mut count) = (0, 0, 0);
        for i in 0..n-1 {
            let binary = 1 << (bytes[i] - b'a');
            if mask & binary == 0 {
                count += 1;
                if count <= k {
                    mask |= binary;
                } else {
                    num += 1;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        (num, mask, count) = (0, 0, 0);
        for i in (1..n).rev() {
            let binary = 1 << (bytes[i] - b'a');
            if mask & binary == 0 {
                count += 1;
                if count <= k {
                    mask |= binary;
                } else {
                    num += 1;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        let mut max_val = 0;
        for i in 0..n {
            let mut seg = left[i][0] + right[i][0] + 2;
            let tot_mask = left[i][1] | right[i][1];
            let tot_count = tot_mask.count_ones() as i32;
            
            if left[i][2] == k && right[i][2] == k && tot_count < 26 {
                seg += 1;
            } else if (tot_count + 1).min(26) <= k {
                seg -= 1;
            }
            max_val = max_val.max(seg);
        }
        max_val
    }
}