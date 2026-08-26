impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        for m in k as usize..=s.len() {
            let mut ans = String::new();
            for i in m..=s.len() {
                let t = &s[i - m..i];
                if t.bytes().filter(|&b| b == b'1').count() == k as usize
                    && (ans.is_empty() || t < ans.as_str())
                {
                    ans = t.to_string();
                }
            }
            if !ans.is_empty() {
                return ans;
            }
        }
        String::new()
    }
}