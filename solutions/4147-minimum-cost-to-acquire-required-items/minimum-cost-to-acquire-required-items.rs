impl Solution {
    pub fn minimum_cost(cost1: i32, cost2: i32, cost_both: i32, need1: i32, need2: i32) -> i64 {
        let mut total_cost: i64 = 0;
        let mut need1 = need1;
        let mut need2 = need2;

        // Buying separately is cheaper; item 3 is unnecessary
        if cost1 + cost2 <= cost_both {
            total_cost = cost1 as i64 * need1 as i64 + cost2 as i64 * need2 as i64;
        } else {
            // Buy item 3 first until one requirement is fulfilled
            let cnt_3 = need1.min(need2);
            total_cost = cnt_3 as i64 * cost_both as i64;

            need1 -= cnt_3;
            need2 -= cnt_3;

            // Type 1 is still needed; choose the cheaper of items 1 and 3
            if need1 > 0 {
                total_cost += need1 as i64 * cost1.min(cost_both) as i64;
            }
            // Type 2 is still needed; choose the cheaper of items 2 and 3
            else if need2 > 0 {
                total_cost += need2 as i64 * cost2.min(cost_both) as i64;
            }
        }

        total_cost
    }
}