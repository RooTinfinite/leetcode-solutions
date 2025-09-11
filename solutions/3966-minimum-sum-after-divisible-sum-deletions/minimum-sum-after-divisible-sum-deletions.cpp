class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // remainder -> earliest index
        unordered_map<int, int> indexMap{{0, n}}; 

        // dp[i] = minimum sum possible starting from index i
        vector<long long> dp(n + 1, 0);

        int sum = 0;

        // Process array from right to left
        for (int i = n - 1; i >= 0; i--) {
            sum = (sum + nums[i]) % k;

            // Default case: keep current element
            dp[i] = nums[i] + dp[i + 1]; 

            // If same remainder seen before → subarray divisible by k
            if (indexMap.count(sum)) {
                dp[i] = min(dp[i], dp[indexMap[sum]]);
            }

            // Update earliest index for this remainder
            indexMap[sum] = i;
        }

        return dp[0];
    }
};