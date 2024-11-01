class Solution {
    // Main method that initializes the permutation process
    // nums: input array to be permuted
    // returns: list containing all possible permutations
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();    // Store all permutations
        backtrack(nums, 0, res);                        // Start backtracking from index 0
        return res;    
    }

    // Recursive backtracking method to generate permutations
    // nums: array being permuted
    // start: current position we're filling
    // res: result list storing all permutations
    private void backtrack(int[] nums, int start, List<List<Integer>> res) {
        // Base case: when we've filled all positions (reached end of array)
        if (start == nums.length) {
            res.add(arrayToList(nums));    // Add current permutation to result
            return;
        }

        // Try each number as the next element in the permutation
        for (int i = start; i < nums.length; i++) {
            swap(nums, start, i);           // Place current number at start position
            backtrack(nums, start + 1, res); // Recursively generate permutations for rest
            swap(nums, start, i);           // Backtrack: restore array to original state
        }
    }
    
    // Helper method to convert int array to List<Integer>
    // arr: input array to convert
    // returns: ArrayList containing array elements
    private List<Integer> arrayToList(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int num : arr) {
            list.add(num);
        }
        return list;
    }
    
    // Helper method to swap two elements in array
    // nums: array containing elements
    // i, j: indices of elements to swap
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}