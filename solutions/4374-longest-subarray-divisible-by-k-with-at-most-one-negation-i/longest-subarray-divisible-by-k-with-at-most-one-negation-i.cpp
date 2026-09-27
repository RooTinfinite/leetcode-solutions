class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), best = 0;
        vector<int> seenAt(k, -1);  // seenAt[v] == l  <=>  v seen for this l
        for (int l = 0; l < n && n - l > best; ++l) {
            long long total = 0;
            for (int r = l; r < n; ++r) {
                total += nums[r];
                seenAt[((2LL * nums[r]) % k + k) % k] = l;
                int s = (total % k + k) % k;
                if (s == 0 || seenAt[s] == l) best = max(best, r - l + 1);
            }
        }
        return best;
    }
};