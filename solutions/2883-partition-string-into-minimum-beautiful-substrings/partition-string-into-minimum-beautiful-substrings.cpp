class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.length(); // Length of the string
        const int INF = 1e9;
        vector<int> dp(n + 1, INF); // Dynamic programming array to store the minimum counts
        
        fill(dp.begin(), dp.end(), INF); // Initialize dp array with INF
        dp[0] = 0; // Base case: No substrings, so count is 0
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue; // Skip if the current character is '0'
            long long num = 0; // Number formed by the substring
            for (int j = i; j < n; j++) {
                num = (num << 1) + s[j] - '0'; // Update the number by shifting bits and adding the current digit
                if (num > pow(10, 18)) break; // Break if the number exceeds the limit
                if (isPowerOfFive(num)) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1); // Update the minimum count if the number is a power of 5
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n]; // Return the minimum count, or -1 if no beautiful substring exists
    }

private:
    bool isPowerOfFive(long long num) {
        if (num == 0) return false; // Zero is not a power of 5
        while (num % 5 == 0) num /= 5; // Divide by 5 until the number is no longer divisible by 5
        return num == 1; // Return true if the number is a power of 5 (after removing all factors of 5)
    }
};