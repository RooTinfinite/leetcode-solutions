class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Size of input array and variable to track maximum value
        int n = nums.size(), mx = 0;

        // Create DP array to store streak lengths
        // Size 100001 because constraints mention nums[i] <= 10^5
        int dp[100001];
        memset(dp, 0, sizeof(dp));

        // Mark all numbers present in input array with 1
        // and track the maximum value
        for(int i = 0; i < n; i++){
            dp[nums[i]] = 1;
            mx = max(mx, nums[i]);
        }

        // Initialize answer as -1 (for when no streak exists)
        int ans = -1;

        // Check each number from 2 up to the maximum value found
        for(int i = 2; i <= mx; i++){
            // If current number exists in our array AND
            // it's a perfect square (by checking if sqrt(i) * sqrt(i) equals i)
            if(dp[i] && (int)sqrt(i) * (int)sqrt(i) == i){
                // Add the streak length of its square root to current streak
                dp[i] = dp[i] + dp[(int)sqrt(i)];
                // Update answer with maximum streak found
                ans = max(ans, dp[i]);
            }
        }

        // If longest streak is 1, it's not valid (need at least 2 numbers)
        if(ans == 1){
            return -1;
        }

        return ans;
    }
};