class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0), suf(n, 0);

        // Compute prefix max
        pref[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        // Compute suffix min
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > pref[i - 1] && nums[i] < suf[i + 1])
                ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                ans += 1;
        }
        return ans;
    }
};