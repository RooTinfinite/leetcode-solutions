impl Solution {
    pub fn maximum_beauty(items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut items = items;
        items.sort_by_key(|x| x[0]);
        
        let mut queries_with_index: Vec<(i32, usize)> = queries.iter()
            .enumerate()
            .map(|(i, &q)| (q, i))
            .collect();
        queries_with_index.sort_by_key(|&(q, _)| q);
        
        let mut res = vec![0; queries.len()];
        let mut max_bea = 0;
        let mut j = 0;
        
        for (query, index) in queries_with_index {
            while j < items.len() && items[j][0] <= query {
                max_bea = max_bea.max(items[j][1]);
                j += 1;
            }
            res[index] = max_bea;
        }
        res
    }
}
