public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> combination = new ArrayList<>();
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrack(nums, k, n, 0, combination, result);
        return result;
    }

    private void backtrack(int[] nums, int k, int n, int start, 
                           List<Integer> combination, List<List<Integer>> result) {
        if (combination.size() == k && n == 0) {
            result.add(new ArrayList<>(combination));
            return;
        }
        for (int i = start; i < nums.length; ++i) {
            if (n < nums[i]) continue; // Skip if current number is greater than remaining sum
            combination.add(nums[i]);
            backtrack(nums, k, n - nums[i], i + 1, combination, result);
            combination.remove(combination.size() - 1); // Remove last element to try the next candidate
        }
    }
}