use std::collections::HashMap;

impl Solution {
    pub fn solve_queries(nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;

        let mut nums_pos: HashMap<i32, Vec<i32>> = HashMap::new();
        for i in 0..n {
            nums_pos.entry(nums[i as usize]).or_insert(Vec::new()).push(i);
        }
        
        for (_, pos) in nums_pos.iter_mut() {
            let x = pos[0];
            let last = *pos.last().unwrap();
            pos.insert(0, last - n);
            pos.push(x + n);
        }
        
        queries
            .iter()
            .map(|&q| {
                let x = nums[q as usize];
                let pos_list = nums_pos.get(&x).unwrap();
                
                if pos_list.len() == 3 {
                    return -1;
                }
                let idx = pos_list.partition_point(|&v| v < q);
                (pos_list[idx + 1] - pos_list[idx]).min(pos_list[idx] - pos_list[idx - 1])
            })
            .collect()
    }
}