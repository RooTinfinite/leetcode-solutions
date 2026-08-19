use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_families(n: i32, reserved_seats: Vec<Vec<i32>>) -> i32 {
        let left = 0b11110000;
        let middle = 0b11000011;
        let right = 0b00001111;

        let mut occupied: HashMap<i32, i32> = HashMap::new();
        for seat in &reserved_seats {
            if seat[1] >= 2 && seat[1] <= 9 {
                let row = seat[0];
                let entry = occupied.entry(row).or_insert(0);
                *entry |= 1 << (seat[1] - 2);
            }
        }

        let mut ans = (n - occupied.len() as i32) * 2;
        for &bitmask in occupied.values() {
            if (bitmask | left) == left || 
               (bitmask | middle) == middle || 
               (bitmask | right) == right {
                ans += 1;
            }
        }
        ans
    }
}