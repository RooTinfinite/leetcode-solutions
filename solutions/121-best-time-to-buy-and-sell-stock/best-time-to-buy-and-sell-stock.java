class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        
        int maxProfit = 0;
        int leftBuy = 0;
        int rightSell = 1;
        
        while (rightSell < prices.length) {
            int currentPrice = prices[rightSell];
            int buyPrice = prices[leftBuy];
            
            if (buyPrice < currentPrice) {
                int currentProfit = currentPrice - buyPrice;
                maxProfit = Math.max(maxProfit, currentProfit);
            } else {
                leftBuy = rightSell;
            }
            
            rightSell++;
        }
        
        return maxProfit;
    }
}