class Solution {
public:
    // Function to check if subarray at indices i and l is alternating
    bool isAlternating(vector<int>& nums, int i, int l) {
        int distance = i - l;
        if (distance % 2 == 1) {
            // Odd distance, check for consecutive increasing elements
            if (nums[i] - nums[l] == 1 && nums[l + 1] - nums[l] == 1)
                return true;
            return false;
        } else {
            // Even distance, check for equal elements
            return nums[i] - nums[l] == 0;
        }
    }

    int alternatingSubarray(vector<int>& nums) {
        int maxLength = 0;
        int l = 0;
        
        for (int i = 1; i < (int)nums.size(); i++) {
            while (!isAlternating(nums, i, l)) {
                l++;
            }
            maxLength = max(maxLength, i - l + 1);
        }
        
        return (maxLength <= 1) ? -1 : maxLength;
    }
};