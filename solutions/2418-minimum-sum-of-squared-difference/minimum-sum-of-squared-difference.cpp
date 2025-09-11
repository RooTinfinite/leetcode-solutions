class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int freq[100001] = {0}, maxDiff = 0;
        for (int i = 0, n = nums1.size(); i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            ++freq[diff];
            maxDiff = max(maxDiff, diff);
        }
        int k = k1 + k2;
        for (int i = maxDiff; i && k; --i) {
            if (!freq[i]) continue;
            int take = min(k, freq[i]);
            freq[i - 1] += take;
            freq[i] -= take;
            k -= take;
        }
        long long res = 0;
        for (int i = 1; i <= maxDiff; ++i) res += 1LL * freq[i] * i * i;
        return res;
    }
};