class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int count = 2, ans = 2;
        for (int i = 2; i < n; i++) {
            if ((long long)arr[i-2] + (long long)arr[i-1] == (long long)arr[i])
                count++;
            else {
                ans = max(ans, count);
                count = 2;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};