class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        constexpr int MOD = 1e9 + 7;
        vector<int> sorted(nums1);
        sort(sorted.begin(), sorted.end());
        long res = 0, gain = 0;
        for (int i = 0, n = nums1.size(); i < n; ++i) {
            int val = nums2[i];
            long diff = abs(nums1[i] - val);
            res += diff;
            if (gain < diff) {    
                auto it = lower_bound(sorted.begin(), sorted.end(), val);
                if (it != sorted.end()) gain = max(gain, diff - abs(*it - val));
                if (it != sorted.begin()) gain = max(gain, diff - abs(*prev(it) - val));
            }
        }
        return (res - gain) % MOD;
    }
};
