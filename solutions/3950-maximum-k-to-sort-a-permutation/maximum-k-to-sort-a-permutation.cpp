class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int mask = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) mask &= nums[i];
        }
        return mask == INT_MAX ? 0 : mask;
    }
};