class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int extra = nums2[n]; 
        long long ans = 0;
        bool found = false;
        int minExtra = 1e5 + 1;

        for (int i = 0; i < n; i++) {
            long long diff = abs(nums1[i] - nums2[i]);
            ans += diff;

            if (!found) {
                int low = min(nums1[i], nums2[i]);
                int high = max(nums1[i], nums2[i]);

                if (extra >= low && extra <= high)
                    found = true;
                else
                    minExtra = min(minExtra, min(abs(nums1[i] - extra), abs(nums2[i] - extra)));
            }
        }

        return ans + (found ? 1 : minExtra + 1);
    }
};