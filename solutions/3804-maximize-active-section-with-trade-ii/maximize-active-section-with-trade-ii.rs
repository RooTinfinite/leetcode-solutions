use std::collections::VecDeque;

impl Solution {
    pub fn max_active_sections_after_trade(s: String, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = s.len();
        let m = queries.len();
        let s_bytes = s.as_bytes();
        
        let mut cnt1: i32 = 0;
        for &c in s_bytes {
            if c == b'1' {
                cnt1 += 1;
            }
        }
        
        // left[i]: represents the length of the continuous block ending at position i, which is the same as s[i]
        let mut left = vec![0i32; n];
        // right[i]: represents the length of the continuous block starting at position i with the same value as s[i]
        let mut right = vec![0i32; n];

        for i in 0..n {
            left[i] = if i > 0 && s_bytes[i-1] == s_bytes[i] {
                left[i-1] + 1
            } else {
                1
            };
        }
        for i in (0..n).rev() {
            right[i] = if i < n - 1 && s_bytes[i+1] == s_bytes[i] {
                right[i+1] + 1
            } else {
                1
            };
        }

        let mut ans = vec![-1i32; m];
        let block_size = (n as f64).sqrt() as usize;
        let block_size = if block_size < 1 { 1 } else { block_size };
        // query with length greater than block length
        let mut long_queries: Vec<[usize; 4]> = Vec::new();

        let brute_force = |l: usize, r: usize| -> i32 {
            let mut i = l;
            let mut best = 0i32;
            let mut prev = i32::MIN;

            while i <= r {
                let start = i;
                while i <= r && s_bytes[i] == s_bytes[start] {
                    i += 1;
                }
                if s_bytes[start] == b'0' {
                    let cur = (i - start) as i32;
                    if prev != i32::MIN && prev + cur > best {
                        best = prev + cur;
                    }
                    prev = cur;
                }
            }
            best
        };

        for i in 0..m {
            let l = queries[i][0] as usize;
            let r = queries[i][1] as usize;
            if r - l + 1 > block_size {
                long_queries.push([l / block_size, l, r, i]);
            } else {
                // queries shorter than block length, brute-force calculation
                ans[i] = cnt1 + brute_force(l, r);
            }
        }

        // sort by the ID of the block where the left endpoint is located as the first keyword, and by the right endpoint as the second keyword
        long_queries.sort_by(|a, b| {
            if a[0] != b[0] {
                a[0].cmp(&b[0])
            } else {
                a[2].cmp(&b[2])
            }
        });

        let mut sub_zero_blocks: VecDeque<i32> = VecDeque::new();
        let mut l_ptr: usize = 0;
        let mut r_ptr: usize = 0;
        let mut best_gain: i32 = 0;

        for i in 0..long_queries.len() {
            let bid = long_queries[i][0];
            let l = long_queries[i][1];
            let r = long_queries[i][2];
            let qid = long_queries[i][3];

            if i == 0 || bid > long_queries[i-1][0] {
                // traverse to a new block, perform initialization operations
                l_ptr = (bid + 1) * block_size - 1; // L is initialized to the right endpoint of the block
                r_ptr = (bid + 1) * block_size;      // R is initialized to the left endpoint of the next block
                sub_zero_blocks.clear();
                best_gain = 0;
            }

            while r_ptr <= r {
                let mut sz = right[r_ptr] as usize;
                if r - r_ptr + 1 < sz {
                    sz = r - r_ptr + 1;
                }
                if s_bytes[r_ptr] == b'0' {
                    if !sub_zero_blocks.is_empty() && r_ptr > 0 && s_bytes[r_ptr-1] == b'0' {
                        if let Some(back) = sub_zero_blocks.pop_back() {
                            sub_zero_blocks.push_back(back + sz as i32);
                        }
                    } else {
                        sub_zero_blocks.push_back(sz as i32);
                    }
                    if sub_zero_blocks.len() >= 2 {
                        let last = *sub_zero_blocks.back().unwrap();
                        let second_last = sub_zero_blocks[sub_zero_blocks.len() - 2];
                        best_gain = best_gain.max(last + second_last);
                    }
                }
                r_ptr += sz;
            }

            // before moving the left endpoint L, backup the value of bestGain
            let tmp_best_gain = best_gain;
            // value of the first element of subZeroBlocks before moving the left endpoint
            let tmp_first_value = sub_zero_blocks.front().copied();
            // the number of digits added from the left during the process of recording the movement of the left endpoint L
            let mut cnt = 0;

            while l_ptr >= l {
                let mut sz = left[l_ptr] as usize;
                if l_ptr - l + 1 < sz {
                    sz = l_ptr - l + 1;
                }
                if s_bytes[l_ptr] == b'0' {
                    if !sub_zero_blocks.is_empty() && l_ptr + 1 < n && s_bytes[l_ptr+1] == b'0' {
                        if let Some(front) = sub_zero_blocks.pop_front() {
                            sub_zero_blocks.push_front(front + sz as i32);
                        }
                    } else {
                        sub_zero_blocks.push_front(sz as i32);
                        cnt += 1;
                    }
                    if sub_zero_blocks.len() >= 2 {
                        let first = *sub_zero_blocks.front().unwrap();
                        let second = sub_zero_blocks[1];
                        best_gain = best_gain.max(first + second);
                    }
                }
                if l_ptr >= sz {
                    l_ptr -= sz;
                } else {
                    break;
                }
            }

            // answering inquiries
            ans[qid] = best_gain + cnt1;
            // restore left endpoint L
            l_ptr = (bid + 1) * block_size - 1;
            if l_ptr >= n { l_ptr = n - 1; }
            // restore bestGain
            best_gain = tmp_best_gain;
            // restore subZeroBlocks
            for _ in 0..cnt {
                sub_zero_blocks.pop_front();
            }
            if let Some(first_val) = tmp_first_value {
                if !sub_zero_blocks.is_empty() {
                    sub_zero_blocks.pop_front();
                    sub_zero_blocks.push_front(first_val);
                }
            }
        }
        ans
    }
}