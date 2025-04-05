class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        // Generate all of the subsets
        generateSubsets(nums, 0, {}, subsets);

        // Compute the XOR total for each subset and add to the result
        int result = 0;
        for (auto& subset : subsets) {
            int subsetXORTotal = 0;
            for (int num : subset) {
                subsetXORTotal ^= num;
            }
            result += subsetXORTotal;
        }
        return result;
    }

private:
    void generateSubsets(const vector<int>& nums, int index, vector<int> subset,
                         vector<vector<int>>& subsets) {
        // Base case: index reached end of nums
        // Add the current subset to subsets
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        // Generate subsets with nums[i]
        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, subsets);
        subset.pop_back();

        // Generate subsets without nums[i]
        generateSubsets(nums, index + 1, subset, subsets);
    }
};