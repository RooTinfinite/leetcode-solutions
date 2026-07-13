class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        // Count total number of zeros
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt0++;
            }
        }

        // Count zeros already present in the last cnt0 positions
        int already = 0;
        for (int i = n - 1; i >= n - cnt0; i--) {
            if (nums[i] == 0) {
                already++;
            }
        }

        return cnt0 - already;
    }
};