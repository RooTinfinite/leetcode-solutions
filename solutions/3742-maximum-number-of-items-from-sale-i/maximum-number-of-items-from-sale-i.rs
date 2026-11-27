impl Solution {
    pub fn maximum_sale_items(items: Vec<Vec<i32>>, budget: i32) -> i32 {
        let budget_usize = budget as usize;
        let mut f = vec![0; budget_usize + 1];
        let mut mn = i32::MAX;
        for item in &items {
            let (factor, price) = (item[0], item[1]);
            mn = mn.min(price);
            let cnt = items.iter().filter(|other| other[0] % factor == 0).count() as i32;
            let price_usize = price as usize;
            for j in (price_usize..=budget_usize).rev() {
                f[j] = f[j].max(f[j - price_usize] + cnt);
            }
        }
        (0..=budget_usize)
            .map(|j| f[j] + (budget - j as i32) / mn)
            .max()
            .unwrap_or(0)
    }
}