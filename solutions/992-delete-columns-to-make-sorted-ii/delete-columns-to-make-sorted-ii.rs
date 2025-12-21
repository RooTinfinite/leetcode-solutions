impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs.len();
        let m = strs[0].len();

        // resolved[i] means strs[i] < strs[i+1] is locked
        let mut resolved = vec![false; n - 1];
        let mut unresolved = n - 1;
        let mut deletions = 0;

        for col in 0..m {
            if unresolved == 0 {
                break;
            }

            let mut bad = false;

            // Check ordering violation
            for i in 0..n - 1 {
                if !resolved[i]
                    && strs[i].as_bytes()[col] > strs[i + 1].as_bytes()[col]
                {
                    bad = true;
                    break;
                }
            }

            if bad {
                deletions += 1;
                continue;
            }

            // Mark resolved row pairs
            for i in 0..n - 1 {
                if !resolved[i]
                    && strs[i].as_bytes()[col] < strs[i + 1].as_bytes()[col]
                {
                    resolved[i] = true;
                    unresolved -= 1;
                }
            }
        }

        deletions
    }
}