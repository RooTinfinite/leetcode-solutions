impl Solution {
    pub fn longest_repeating(s: String, query_characters: String, query_indices: Vec<i32>) -> Vec<i32> {
        let n = s.len();
        let s = s.as_bytes();
        let qc = query_characters.as_bytes();
        let mut pre = vec![0; 4 * n];
        let mut suf = vec![0; 4 * n];
        let mut max_len = vec![0; 4 * n];
        let mut left_char = vec![0u8; 4 * n];
        let mut right_char = vec![0u8; 4 * n];

        fn push_up(pre: &mut [i32], suf: &mut [i32], max_len: &mut [i32], left_char: &mut [u8], right_char: &mut [u8], u: usize, l: usize, r: usize) {
            let mid = (l + r) >> 1;
            let left_len = (mid - l + 1) as i32;
            let right_len = (r - mid) as i32;
            let left = u << 1;
            let right = u << 1 | 1;
            left_char[u] = left_char[left];
            right_char[u] = right_char[right];
            pre[u] = pre[left];
            if pre[left] == left_len && right_char[left] == left_char[right] {
                pre[u] = pre[left] + pre[right];
            }
            suf[u] = suf[right];
            if suf[right] == right_len && right_char[left] == left_char[right] {
                suf[u] = suf[right] + suf[left];
            }
            max_len[u] = max_len[left].max(max_len[right]);
            if right_char[left] == left_char[right] {
                max_len[u] = max_len[u].max(suf[left] + pre[right]);
            }
        }

        fn build(pre: &mut [i32], suf: &mut [i32], max_len: &mut [i32], left_char: &mut [u8], right_char: &mut [u8], s: &[u8], u: usize, l: usize, r: usize) {
            if l == r {
                pre[u] = 1;
                suf[u] = 1;
                max_len[u] = 1;
                left_char[u] = s[l];
                right_char[u] = s[l];
                return;
            }
            let mid = (l + r) >> 1;
            build(pre, suf, max_len, left_char, right_char, s, u << 1, l, mid);
            build(pre, suf, max_len, left_char, right_char, s, u << 1 | 1, mid + 1, r);
            push_up(pre, suf, max_len, left_char, right_char, u, l, r);
        }

        fn update(pre: &mut [i32], suf: &mut [i32], max_len: &mut [i32], left_char: &mut [u8], right_char: &mut [u8], u: usize, l: usize, r: usize, pos: usize, ch: u8) {
            if l == r {
                left_char[u] = ch;
                right_char[u] = ch;
                return;
            }
            let mid = (l + r) >> 1;
            if pos <= mid {
                update(pre, suf, max_len, left_char, right_char, u << 1, l, mid, pos, ch);
            } else {
                update(pre, suf, max_len, left_char, right_char, u << 1 | 1, mid + 1, r, pos, ch);
            }
            push_up(pre, suf, max_len, left_char, right_char, u, l, r);
        }

        build(&mut pre, &mut suf, &mut max_len, &mut left_char, &mut right_char, s, 1, 0, n - 1);

        let k = query_indices.len();
        let mut ans = vec![0; k];
        for i in 0..k {
            update(&mut pre, &mut suf, &mut max_len, &mut left_char, &mut right_char, 1, 0, n - 1, query_indices[i] as usize, qc[i]);
            ans[i] = max_len[1];
        }
        ans
    }
}