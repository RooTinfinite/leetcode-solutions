#include <vector>
#include <algorithm> // Include algorithm header for the min and max functions

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;   // Variable to store the calculated maximum profit
        int min_price = prices[0]; // Initialize the minimum price to the first price

        // Loop through all the prices
        for (int price : prices) {
            // Update max_profit if the difference between current price and min_price is greater than current max_profit
            max_profit = max(max_profit, price - min_price);
          
            // Update min_price if the current price is less than the current min_price
            min_price = min(min_price, price);
        }
      
        return max_profit; // Return the calculated maximum profit
    }
};
