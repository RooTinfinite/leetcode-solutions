impl Solution {
    // Helper function to find combinations recursively
    fn find_combinations(
        index: usize,
        target: i32,
        candidates: &Vec<i32>,
        current: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        // Base case: found a valid combination
        if target == 0 {
            result.push(current.clone());
            return;
        }

        // Try all possible numbers from current index
        for i in index..candidates.len() {
            // Only proceed if current number doesn't exceed target
            if candidates[i] <= target {
                // Include current number in combination
                current.push(candidates[i]);

                // Recursive call with same index (allowing reuse)
                Self::find_combinations(
                    i,
                    target - candidates[i],
                    candidates,
                    current,
                    result,
                );

                // Backtrack by removing last added number
                current.pop();
            }
        }
    }

    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut current = Vec::new();
        Self::find_combinations(0, target, &candidates, &mut current, &mut result);
        result
    }
}