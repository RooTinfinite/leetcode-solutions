class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrack(nums, k, n, 0, combination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, int k, int n, int start, 
                   std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (combination.size() == k && n == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (n < nums[i]) continue; // Skip if current number is greater than remaining sum
            combination.push_back(nums[i]);
            backtrack(nums, k, n - nums[i], i + 1, combination, result);
            combination.pop_back(); // Remove last element to try the next candidate
        }
    }
};