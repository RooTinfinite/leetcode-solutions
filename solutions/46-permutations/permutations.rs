impl Solution {
    // Helper function for generating permutations
    fn solve(nums: &mut Vec<i32>, l: usize, r: usize, result: &mut Vec<Vec<i32>>) {
        if l == r {
            result.push(nums.clone());
            return;
        }
        
        for i in l..=r {
            // Swap elements
            nums.swap(l, i);
            
            // Recursive call
            Self::solve(nums, l + 1, r, result);
            
            // Backtrack by swapping back
            nums.swap(l, i);
        }
    }

    pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let len = nums.len();
        if len > 0 {
            Self::solve(&mut nums, 0, len - 1, &mut result);
        }
        result
    }
}