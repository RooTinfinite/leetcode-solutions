impl Solution {
    pub fn minimized_maximum(store_count: i32, product_quantities: Vec<i32>) -> i32 {
        let max_quantity = *product_quantities.iter().max().unwrap();
        let mut left = 1;
        let mut right = max_quantity;
        let mut result = 0;
        
        while left <= right {
            let mid = left + (right - left) / 2;
            if Self::can_distribute_products(mid, store_count, &product_quantities) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        result
    }
    
    fn can_distribute_products(max_products_per_store: i32, store_count: i32, quantities: &Vec<i32>) -> bool {
        let mut required_stores = 0;
        
        for &quantity in quantities {
            required_stores += (quantity + max_products_per_store - 1) / max_products_per_store;
        }
        
        required_stores <= store_count
    }
}