class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1e9+7;
        long long ans = 1;
        bool started = false;
        int zeroCount = 0;

        for(int num : nums) {
            if(num == 1) {
                if(!started) {
                    // first '1' found, start counting
                    started = true;
                } else {
                    // multiply with zeros in between
                    ans = (ans * zeroCount) % mod;
                }
                zeroCount = 1; // reset to 1 because we "include" this '1'
            }
            else if(started) {
                zeroCount++;
            }
        }

        return started ? ans : 0;
    }
};