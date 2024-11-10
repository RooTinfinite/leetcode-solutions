class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices or len(prices) < 2:
            return 0
            
        max_profit = 0
        left_buy = 0
        right_sell = 1 #you can't buy later and sell earlier, unless you're doctor who :)
        
        while right_sell < len(prices):
            current_price = prices[right_sell]
            buy_price = prices[left_buy]
            
            if buy_price < current_price:
                current_profit = current_price - buy_price
                max_profit = max(max_profit, current_profit)
            else:
                left_buy = right_sell
                
            right_sell += 1
            
        return max_profit