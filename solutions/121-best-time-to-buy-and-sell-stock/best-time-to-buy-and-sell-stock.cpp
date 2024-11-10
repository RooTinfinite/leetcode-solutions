class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int currentPrice : prices) {
            minPrice = min(currentPrice, minPrice);
            maxProfit = max(maxProfit, currentPrice - minPrice);
        }
        
        return maxProfit;
    }
};
