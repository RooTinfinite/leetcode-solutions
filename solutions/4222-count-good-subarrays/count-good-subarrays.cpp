class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prev_one(31, -1), next_one(31, n);
        vector<int> L(n, 0), R(n, n - 1);
        
        // Find the furthest left we can go without adding new bits
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 31; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    L[i] = max(L[i], prev_one[bit] + 1);
                } else {
                    prev_one[bit] = i;
                }
            }
        }
        
        // Find the furthest right we can go without adding new bits
        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 31; bit++) {
                if ((nums[i] & (1 << bit)) == 0) {
                    R[i] = min(R[i], next_one[bit] - 1);
                } else {
                    next_one[bit] = i;
                }
            }
        }
        
        long long ans = 0;
        unordered_map<int, int> last_idx;
        
        // Calculate valid subarrays anchored at 'i'
        for (int i = 0; i < n; i++) {
            int l = L[i], r = R[i];
            
            // Prevent duplicate counting for the same OR maximum
            if (last_idx.count(nums[i])) {
                l = max(l, last_idx[nums[i]] + 1);
            }
            last_idx[nums[i]] = i;
            
            ans += 1LL * (i - l + 1) * (r - i + 1);
        }
        
        return ans;
    }
};