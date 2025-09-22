class Solution {
public:
    unordered_map<int, int> dp;

    int helper(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];

        // If n is already a power of 2
        if ((n & (n - 1)) == 0) return dp[n] = 1;

        // Find nearest powers of 2
        int p = 1;
        while (p < n) p <<= 1;

        // Try both: add or subtract power of 2
        int add = 1 + helper(p - n);         // Add (to reach nearest higher power)
        int sub = 1 + helper(n - (p >> 1));  // Subtract (to reach nearest lower power)

        return dp[n] = min(add, sub);
    }

    int minOperations(int n) {
        return helper(n);
    }
};