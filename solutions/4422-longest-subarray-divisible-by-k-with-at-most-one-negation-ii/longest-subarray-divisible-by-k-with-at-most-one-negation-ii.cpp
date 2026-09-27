class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = ((prefix[i] + nums[i]) % k + k) % k;

        vector<int> first(k, n + 1), last(k, -1);
        for (int i = 0; i <= n; ++i) last[prefix[i]] = i;
        for (int i = n; i >= 0; --i) first[prefix[i]] = i;

        int best = 0;
        for (int c = 0; c < k; ++c) best = max(best, last[c] - first[c]);   // no negation

        vector<int> doubled(n);
        for (int i = 0; i < n; ++i) doubled[i] = ((2 * nums[i]) % k + k) % k;

        vector<int> order(k);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return first[a] > first[b]; });

        vector<int> nxt(k, n + 1);
        int i = n - 1;
        for (int c : order) {
            int start = first[c];
            if (start > n) continue;
            for (; i >= start; --i) nxt[doubled[i]] = i;
            for (int v = 0; v < k; ++v) {
                int end = last[(c + v) % k];
                if (nxt[v] < end) best = max(best, end - start);
            }
        }
        return best;
    }
};