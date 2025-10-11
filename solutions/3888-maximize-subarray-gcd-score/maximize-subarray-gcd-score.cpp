class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> powerOf2(n);
        for(int i = 0; i < n; i++) {
            for(int x = nums[i]; x % 2 == 0; x /= 2) {
                powerOf2[i]++;
            }
        }
        long long ans = 0;
        for(int l = 0; l < n; l++) {
            int gcdVal = 0;
            int minPower = 100, minPowerCnt = 0;
            for(int r = l; r < n; r++) {
                gcdVal = gcd(gcdVal, nums[r]);
                if(powerOf2[r] < minPower) {
                    minPower = powerOf2[r], minPowerCnt = 1;
                }else if(powerOf2[r] == minPower) {
                    minPowerCnt++;
                }
                if(k >= minPowerCnt) {
                    ans = max(ans, 1LL * (r - l + 1) * gcdVal * 2);   
                }else {
                    ans = max(ans, 1LL * (r - l + 1) * gcdVal);
                }
            }
        }
        return ans;
    }
};