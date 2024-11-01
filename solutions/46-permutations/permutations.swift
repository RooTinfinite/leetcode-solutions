class Solution {
    // Helper function that generates all permutations using backtracking
    private func solve(_ nums: inout [Int], _ l: Int, _ r: Int, _ result: inout [[Int]]) {
        // Base case: when left index equals right index
        if l == r {
            result.append(nums)
            return
        }
        
        // Try all possible elements at position 'l'
        for i in l...r {
            // 1. Swap current element with element at position 'l'
            nums.swapAt(l, i)
            
            // 2. Recursively generate permutations for remaining elements
            solve(&nums, l + 1, r, &result)
            
            // 3. Backtrack: restore array to original state by swapping back
            nums.swapAt(l, i)
        }
    }
    
    // Main function that initializes the permutation generation
    func permute(_ nums: [Int]) -> [[Int]] {
        var result: [[Int]] = []  // Stores all permutations
        var numsCopy = nums       // Create mutable copy of input array
        solve(&numsCopy, 0, nums.count - 1, &result)
        return result
    }
}