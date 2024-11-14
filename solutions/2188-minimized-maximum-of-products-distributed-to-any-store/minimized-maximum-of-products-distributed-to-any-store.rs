impl Solution {
    pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
        fn can_distribute(x: i32, quantities: &Vec<i32>, n: i32) -> bool {
            let mut stores = 0;
            for &q in quantities {
                stores += (q + x - 1) / x;
            }
            stores <= n
        }
        
        let mut left = 1;
        let mut right = *quantities.iter().max().unwrap();
        let mut result = 0;
        
        while left <= right {
            let x = (left + right) / 2;
            if can_distribute(x, &quantities, n) {
                result = x;
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        
        result
    }
}