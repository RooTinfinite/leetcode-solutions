/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = prices[0];
    let maxProfit = 0;

    for (let i = 1; i < prices.length; i++) {
        // Update minPrice if we find a lower price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            // Calculate profit if sold at the current price
            let profit = prices[i] - minPrice;
            // Update maxProfit if this profit is higher
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
};