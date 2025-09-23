class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
         int n = nums.size();
        if (n == 0) {
            // Handle the case when the input vector is empty
            return 0;
        }

        int maxSubsetSize = pow(2, n);
        long long maxStrength = INT_MIN;

        for (int mask = 1; mask < maxSubsetSize; mask++) {
            long long strength = 1;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    strength *= nums[i];
                }
            }

            maxStrength = max(maxStrength, strength);
        }

        return maxStrength;
    }
};