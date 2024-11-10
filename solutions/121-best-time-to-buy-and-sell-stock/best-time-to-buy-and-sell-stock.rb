def max_profit(prices)
    min_price = Float::INFINITY
    max_profit = 0
    
    prices.each do |current_price|
        min_price = [current_price, min_price].min
        max_profit = [max_profit, current_price - min_price].max
    end
    
    max_profit
end