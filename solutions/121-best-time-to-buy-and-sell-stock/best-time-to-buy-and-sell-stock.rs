impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.len() < 2 {
            return 0;
        }
        
        let mut max_profit = 0;
        let mut left_buy = 0;
        let mut right_sell = 1;
        
        while right_sell < prices.len() {
            let current_price = prices[right_sell];
            let buy_price = prices[left_buy];
            
            if buy_price < current_price {
                let current_profit = current_price - buy_price;
                max_profit = max_profit.max(current_profit);
            } else {
                left_buy = right_sell;
            }
            
            right_sell += 1;
        }
        
        max_profit
    }
}