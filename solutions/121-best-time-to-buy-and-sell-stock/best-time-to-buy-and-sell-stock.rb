def max_profit(prices)
    return 0 if prices.nil? || prices.length < 2
    
    max_profit = 0
    left_buy = 0
    right_sell = 1
    
    while right_sell < prices.length
        current_price = prices[right_sell]
        buy_price = prices[left_buy]
        
        if buy_price < current_price
            current_profit = current_price - buy_price
            max_profit = [max_profit, current_profit].max
        else
            left_buy = right_sell
        end
        
        right_sell += 1
    end
    
    max_profit
end