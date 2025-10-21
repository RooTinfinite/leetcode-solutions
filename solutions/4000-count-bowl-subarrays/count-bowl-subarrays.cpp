class Solution {
public:
    using ll = long long;
    ll bowlSubarrays(vector<int>& nums) {
        ll res = 0;
        vector<int> stk;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!stk.empty() and nums[stk.back()] < nums[i]) {
                if (i - stk.back() >= 2) {
                    res++;
                }
                stk.pop_back();
            }
            if (!stk.empty() and i - stk.back() >= 2) {
                res++;
            }
            stk.push_back(i);
        }
        return res;
    }
};