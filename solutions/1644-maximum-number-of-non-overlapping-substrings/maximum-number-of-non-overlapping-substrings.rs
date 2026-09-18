#[derive(Clone)]
struct Seg {
    left: i32,
    right: i32,
}

impl Seg {
    fn new(left: i32, right: i32) -> Self {
        Self { left, right }
    }
}

impl Solution {
    pub fn max_num_of_substrings(s: String) -> Vec<String> {
        let chars: Vec<char> = s.chars().collect();

        let mut seg = vec![Seg::new(-1, -1); 26];

        // Preprocess the left and right endpoints.
        for i in 0..chars.len() {
            let char_idx = (chars[i] as u8 - b'a') as usize;

            if seg[char_idx].left == -1 {
                seg[char_idx].left = i as i32;
                seg[char_idx].right = i as i32;
            } else {
                seg[char_idx].right = i as i32;
            }
        }

        for i in 0..26 {
            if seg[i].left != -1 {
                let mut j = seg[i].left;

                while j <= seg[i].right {
                    let char_idx =
                        (chars[j as usize] as u8 - b'a') as usize;

                    if seg[i].left <= seg[char_idx].left
                        && seg[char_idx].right <= seg[i].right
                    {
                    } else {
                        seg[i].left =
                            seg[i].left.min(seg[char_idx].left);
                        seg[i].right =
                            seg[i].right.max(seg[char_idx].right);
                        j = seg[i].left;
                    }

                    j += 1;
                }
            }
        }

        // Greedily select intervals.
        seg.sort_by(|a, b| {
            if a.right == b.right {
                b.left.cmp(&a.left)
            } else {
                a.right.cmp(&b.right)
            }
        });

        let mut ans = Vec::new();
        let mut end = -1;

        for segment in seg {
            let left = segment.left;
            let right = segment.right;

            if left == -1 {
                continue;
            }

            if end == -1 || left > end {
                end = right;

                ans.push(
                    chars[left as usize..=right as usize]
                        .iter()
                        .collect::<String>(),
                );
            }
        }

        ans
    }
}