impl Solution {
    pub fn maximum_beauty(mut items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        // Step 1: Sort items by price in ascending order
        items.sort_by_key(|item| item[0]);
        
        // Step 2: Extract prices and beauties into separate vectors
        let prices: Vec<i32> = items.iter().map(|item| item[0]).collect();
        let beauties: Vec<i32> = items.iter().map(|item| item[1]).collect();
        
        // Step 3: Create running maximum beauty array
        let mut max_beauties = vec![0];
        let mut current_max = 0;
        for &beauty in beauties.iter() {
            current_max = current_max.max(beauty);
            max_beauties.push(current_max);
        }
        
        // Step 4: Process each query using binary search
        queries.iter().map(|&query| {
            let index = prices.partition_point(|&x| x <= query);
            max_beauties[index]
        }).collect()
    }
}