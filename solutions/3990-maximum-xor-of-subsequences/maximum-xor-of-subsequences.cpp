class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> temp(32, 0);
        for (int num : nums) {
            for (int i = 31; i >= 0; i--) {
                if (!(num & (1 << i))) continue;
                if (!temp[i]) {
                    temp[i] = num;
                    break;
                }
                num ^= temp[i];
            }
        }

        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            ans = max(ans, ans ^ temp[i]);
        }
        return ans;

    }
};