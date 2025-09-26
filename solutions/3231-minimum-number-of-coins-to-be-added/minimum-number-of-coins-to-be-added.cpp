class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        
        // Get the number of coins.
        int n = coins.size();
        // 'currentAchieved' is the maximum sum we can form using the coins we've processed.
        // It means we can form every integer sum in the range [1, currentAchieved].
        long long currentAchieved = 0;
        // 'index' points to the current coin we are considering from the sorted array.
        int index = 0;
        // 'ans' counts the number of coins we need to add.
        int ans=0;

        // Sorting is crucial for the greedy approach. It ensures we always consider
        // the smallest available coin to extend our reach.
        sort(coins.begin(), coins.end());

        // We continue until we can form all sums up to the target.
        while (currentAchieved < target) {
            // Check if we can use an existing coin to extend our reach.
            // The next number we need to be able to form is 'currentAchieved + 1'.
            // If the current coin is less than or equal to this value, we can use it.
            if (index < n && coins[index] <= currentAchieved + 1) {
                // If we use this coin, our new maximum achievable sum increases by the coin's value.
                currentAchieved += coins[index];
                index++;
            } else {
                // If we're here, it means we have a "gap". We cannot form 'currentAchieved + 1'.
                // The next available coin is too large, or we've run out of coins.
                // To fix this, we must add a new coin. The most efficient coin to add is
                // one with the value 'currentAchieved + 1'.
                
                // By adding 'currentAchieved + 1', our new reachable range extends to
                // 'currentAchieved + (currentAchieved + 1)'.
                currentAchieved = 2 * currentAchieved + 1;
                
                // Increment the count of added coins.
                ans++;
            }
        }

        return ans;
    }
};