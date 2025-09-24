class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> firstDigit(n);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val >= 10) val /= 10;
            firstDigit[i] = val;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(firstDigit[i], nums[j] % 10) == 1) ++ans;
            }
        }
        return ans;
    }
};