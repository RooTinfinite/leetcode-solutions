impl Solution {
    pub fn build_array(mut target: Vec<i32>, n: i32) -> Vec<String> {
        let mut ans = vec![];
        let mut i = 1;
        while target.len() > 0 {
            ans.append(&mut match i == target[0] {
                true => {
                    target.remove(0);
                    vec!["Push"]
                },
                false => vec!["Push", "Pop"]
            });
            i += 1;
        }
        ans
            .into_iter()
            .map(|s| s.to_string())
            .collect()
    }
}