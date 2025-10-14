#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cstring>

// Use built-in popcount for performance, matching Python's 'count_set_bits'
#ifdef _MSC_VER
#include <intrin.h>
#define count_set_bits(n) __popcnt(n)
#else
#define count_set_bits(n) __builtin_popcount(n)
#endif

// Global precomputation is mimicked using a static map inside the method.
// This ensures it runs only once, just like Python's module-level code.
static std::unordered_map<int, int> dp1;

class Solution {
public:
    long long popcountDepth(long long n, int k) {
        // Precompute popcount-depths up to 64, static ensures one-time initialization.
        if (dp1.empty()) {
            dp1[1] = 0;
            for (int i = 2; i < 65; ++i) {
                dp1[i] = 1 + dp1[count_set_bits(i)];
            }
        }

        if (k == 0) {
            return 1; // Only x=1 has a popcount-depth of 0.
        }

        // The digit DP function, implemented as a lambda for conciseness.
        std::function<long long(int, int, bool)> fun;
        std::string binary_num;
        std::unordered_set<int> subset;
        long long dp[65][65][2];

        // Find all popcounts `c` such that depth(c) = k-1.
        for (auto const& [key, val] : dp1) {
            if (val == k - 1) {
                subset.insert(key);
            }
        }

        // Convert n to its binary string representation.
        if (n == 0) {
            binary_num = "0";
        } else {
            long long temp_n = n;
            while (temp_n > 0) {
                binary_num += ((temp_n & 1) ? '1' : '0');
                temp_n >>= 1;
            }
            std::reverse(binary_num.begin(), binary_num.end());
        }
        
        // Initialize memoization table with -1.
        memset(dp, -1, sizeof(dp));
        const int len = binary_num.length();

        // Define the recursive DP logic, capturing local state.
        fun = [&](int index, int ones, bool tight) -> long long {
            if (index == len) { // Base case: a full number is formed.
                return subset.count(ones) ? 1 : 0;
            }

            if (dp[index][ones][tight] != -1) { // Return memoized result.
                return dp[index][ones][tight];
            }

            long long ans = 0;
            int limit = tight ? (binary_num[index] - '0') : 1; // Set upper bound for current bit.

            for (int d = 0; d <= limit; ++d) {
                bool new_tight = tight && (d == limit); // Update tight constraint for next state.
                ans += fun(index + 1, ones + d, new_tight);
            }

            return dp[index][ones][tight] = ans; // Memoize and return.
        };

        long long cnt = fun(0, 0, true); // Start DP from the most significant bit.

        // Correct the count for x=1 when k=1.
        // The DP counts x=1 (popcount=1) but its depth is 0, not 1.
        if (k == 1 && subset.count(1)) {
            cnt -= 1;
        }

        return cnt;
    }
};