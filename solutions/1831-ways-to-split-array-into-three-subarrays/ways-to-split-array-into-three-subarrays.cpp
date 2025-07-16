// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        long mod = 1e9+7, ans = 0;
        for (int i = 1; i < A.size(); ++i) A[i] += A[i - 1];
        long N = A.size(), i = 0, j = 0, k = 0;
        for (; i < N; ++i) {
            long left = A[i];
            j = max(i + 1, j); // `j` is at least one greater than `i`.
            while (j < N && A[j] - left < left) ++j; // find the smallest `j` that satisfies `mid >= left`
            if (j >= N) break; // No room for `k`. Break
            k = max(k, j);
            while (k < N - 1 && A.back() - A[k] >= A[k] - A[i]) ++k;
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};