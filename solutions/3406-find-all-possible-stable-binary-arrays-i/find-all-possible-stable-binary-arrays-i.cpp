class Solution {
public:
    #define ll long long // Define a macro 'll' for 'long long' data type
    ll Mod = 1e9 + 7; 
    int dp[201][201][201][2]; // Define a 4D array 'dp' to store dynamic programming results
    
    // Recursive function 'fun' to calculate the number of stable arrays
    ll fun(int zero, int one, int cnt, int last, int limit) {
        
        // Base case: if the count exceeds the limit, return 0
        if (cnt > limit) return 0;
        
        // Base case: if either zero or one becomes negative, return 0
        if (zero < 0 or one < 0) return 0;
        
        // Base case: if both zero and one become zero, return 1
        if (zero == 0 and one == 0) return 1;
        
        // If the result is already calculated, return the stored value
        if (dp[zero][one][cnt][last] != -1) return dp[zero][one][cnt][last];
        
        // Variable to store the temporary result
        ll temp = 0;
        
        // If the last element was 0
        if (last == 0) {
            // Recursively call 'fun' for the next state with zero decremented and one same
            temp += fun(zero - 1, one, cnt + 1, 0, limit);
            temp %= Mod; // Modulo operation to prevent overflow
            // Recursively call 'fun' for the next state with one decremented and zero same
            temp += fun(zero, one - 1, 1, 1, limit);
            temp %= Mod; // Modulo operation to prevent overflow
        } else { // If the last element was 1
            // Recursively call 'fun' for the next state with zero decremented and one same
            temp += fun(zero - 1, one, 1, 0, limit);
            temp %= Mod; // Modulo operation to prevent overflow
            // Recursively call 'fun' for the next state with one decremented and zero same
            temp += fun(zero, one - 1, cnt + 1, 1, limit);
            temp %= Mod; // Modulo operation to prevent overflow
        }
        // Store the result in the dp array and return
        dp[zero][one][cnt][last] = temp;
        return temp;
    }
    
    // Function to calculate the number of stable arrays
    int numberOfStableArrays(int zero, int one, int limit) {
        // Initialize dp array with -1
        memset(dp, -1, sizeof(dp));
        // Call the 'fun' function to calculate the number of stable arrays
        ll ans = fun(zero, one, 0, 0, limit);
        ans %= Mod; // Modulo operation to prevent overflow
        return ans; // Return the result
    }
};