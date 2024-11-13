class Solution {
private:
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        return r;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i];
            int up = upper - nums[i];
            res += binSearch(nums, i + 1, nums.size() - 1, up + 1) - 
                   binSearch(nums, i + 1, nums.size() - 1, low);
        }
        return res;
    }
};