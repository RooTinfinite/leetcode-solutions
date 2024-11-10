impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = i32::MAX;
        let mut max_profit = 0;
        
        for current_price in prices {
            min_price = min_price.min(current_price);
            max_profit = max_profit.max(current_price - min_price);
        }
        
        return max_profit;
    }
}