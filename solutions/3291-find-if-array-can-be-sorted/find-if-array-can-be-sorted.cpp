class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        // Avoid modifying the input directly
        // Create a copy of the input array
        vector<int> values = nums;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (values[j] <= values[j + 1]) {
                    // No swap needed
                    continue;
                } else {
                    if (__builtin_popcount(nums[j]) ==
                        __builtin_popcount(nums[j + 1])) {
                        // Swap the elements
                        swap(values[j], values[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};