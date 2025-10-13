class Solution {
public:
    vector<int> onceTwice(vector<int>& nums) {
        vector<unsigned int> dp = {~0u, 0, 0};
        for (unsigned int x : nums) {
            for (int i = 0, temp = dp[2] & x; i < 3; ++i) {
                const int mask = x & dp[i];
                dp[i] ^= mask;
                dp[i] |= temp;
                temp = mask;
            }
        }

        vector<unsigned int> ddp = {~0u, 0, 0};
        for (unsigned int x : nums) {
            if ((x & dp[1]) != dp[1]) continue;
            if (x & dp[2]) continue;
            for (int i = 0, temp = ddp[2] & x; i < 3; ++i) {
                const int mask = x & ddp[i];
                ddp[i] ^= mask;
                ddp[i] |= temp;
                temp = mask;
            }
        }
        return {(int) ddp[1], (int) ((ddp[1] ^ dp[1]) | dp[2])};
        
    }
};
