class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sz = n / k;
        for (int i = 0; i < n; i += sz)
            for (int l = i, r = l + sz - 1; l < r; l++, r--)
                swap(nums[l], nums[r]);
        return nums;
    }
};