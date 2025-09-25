class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = i; j < n && nums[j] <= 2 * num; ++j) res = max(res, num ^ nums[j]);
        }
        return res;
    }
};