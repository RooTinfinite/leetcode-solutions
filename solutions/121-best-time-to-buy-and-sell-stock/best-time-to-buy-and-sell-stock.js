// JavaScript

var maxProfit = function(prices) {
    if (!prices || prices.length < 2) {
        return 0;
    }
    
    let maxProfit = 0;
    let leftBuy = 0;
    let rightSell = 1;
    
    while (rightSell < prices.length) {
        const currentPrice = prices[rightSell];
        const buyPrice = prices[leftBuy];
        
        if (buyPrice < currentPrice) {
            const currentProfit = currentPrice - buyPrice;
            maxProfit = Math.max(maxProfit, currentProfit);
        } else {
            leftBuy = rightSell;
        }
        
        rightSell++;
    }
    
    return maxProfit;
};