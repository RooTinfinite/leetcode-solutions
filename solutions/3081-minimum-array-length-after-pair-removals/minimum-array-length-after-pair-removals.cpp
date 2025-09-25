class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), mid = nums[n / 2];
        auto right = upper_bound(nums.begin() , nums.end() , mid);
        auto left = lower_bound(nums.begin() , nums.end() , mid);
        int freq = right - left;
        return (freq > n / 2) ? (2 * freq - n) : (n & 1);
    }
};