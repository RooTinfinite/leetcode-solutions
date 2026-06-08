class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int uniqueFlav = 0;

        // Store the total number of unique flavors in the array.
        unordered_map<int, int> flavFreq;
        for (int c : candies) {
            if (++flavFreq[c] == 1) {
                uniqueFlav++;
            }
        }

        // Get the flavors used completely in the window.
        // It is implied when the frequency of a flavor becomes zero.
        int usedInWindow = 0;
        for (int i = 0; i < k; i++) {
            if (--flavFreq[candies[i]] == 0) {
                usedInWindow++;
            }
        }

        // Get the flavors in the remaining array currently.
        int maxFlav = uniqueFlav - usedInWindow;
        // Keep sliding the current window by one towards right.
        // Get the updated number of flavors in the current window.
        for (int i = k; i < candies.size(); i++) {
            // Remove the candy on the left end from the window
            // And if that candy is the only instance of the flavor,
            // Decrement the used flavors count.
            if (++flavFreq[candies[i - k]] == 1) {
                usedInWindow--;
            }

            // Add the candy on the right end at the ith index.
            // And if now all instances of the flavor are within the window
            // Increment the used counter by one.
            if (--flavFreq[candies[i]] == 0) {
                usedInWindow++;
            }
            maxFlav = max(maxFlav, uniqueFlav - usedInWindow);
        }

        return maxFlav;
    }
};