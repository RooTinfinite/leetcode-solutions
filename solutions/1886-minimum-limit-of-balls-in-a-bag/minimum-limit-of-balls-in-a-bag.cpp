class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int x : nums) {
                cnt += (x - 1) / m;
                if (cnt > k) break;
            }
            cnt <= k ? r = m : l = m + 1;
        }
        return r;
    }
};