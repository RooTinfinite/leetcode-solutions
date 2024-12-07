class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = l + (r - l) / 2, s = 0;
            for (int x : nums) if ((s += (x - 1) / m) > k) break;
            s <= k ? r = m : l = m + 1;
        }
        return r;
    }
};