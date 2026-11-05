struct SwapFenwick {
    counts: Vec<i32>,
    sums: Vec<i64>,
    step: usize,
}

impl SwapFenwick {
    fn new(size: usize) -> Self {
        let mut step = 1;
        while step * 2 <= size {
            step *= 2;
        }
        Self {
            counts: vec![0; size + 1],
            sums: vec![0; size + 1],
            step,
        }
    }

    fn add(&mut self, rank: usize, value: i32, delta: i32) {
        let mut i = rank + 1;
        while i < self.counts.len() {
            self.counts[i] += delta;
            self.sums[i] += value as i64 * delta as i64;
            i += i & i.wrapping_neg();
        }
    }

    fn smallest(&self, mut count: i32, values: &[i32]) -> (i32, i64) {
        if count == 0 {
            return (0, 0);
        }

        let mut index = 0;
        let mut sum = 0i64;
        let mut step = self.step;

        while step > 0 {
            let next = index + step;
            if next < self.counts.len() && self.counts[next] < count {
                count -= self.counts[next];
                sum += self.sums[next];
                index = next;
            }
            step >>= 1;
        }

        let value = values[index];
        (value, sum + count as i64 * value as i64)
    }
}

impl Solution {
    pub fn max_sum(nums: Vec<i32>, length: i32, k: i32) -> i64 {
        let n = nums.len();
        let length = length as usize;
        let outside_count = (n - length) as i32;
        let limit = k.min(length as i32).min(outside_count);

        let mut values = nums.clone();
        values.sort_unstable();
        values.dedup();

        let ranks: Vec<usize> = nums
            .iter()
            .map(|value| values.binary_search(value).unwrap())
            .collect();

        let mut inside = SwapFenwick::new(values.len());
        let mut outside = SwapFenwick::new(values.len());
        let mut window_sum = 0i64;
        let total_sum: i64 = nums.iter().map(|&value| value as i64).sum();

        for i in 0..n {
            if i < length {
                inside.add(ranks[i], nums[i], 1);
                window_sum += nums[i] as i64;
            } else {
                outside.add(ranks[i], nums[i], 1);
            }
        }

        let mut answer = i64::MIN;

        for start in 0..=n - length {
            let mut low = 0;
            let mut high = limit;

            while low < high {
                let mid = low + (high - low + 1) / 2;
                let removed = inside.smallest(mid, &values).0;
                let added = outside.smallest(outside_count - mid + 1, &values).0;

                if added > removed {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            let candidate = if low == 0 {
                window_sum
            } else {
                let removed_sum = inside.smallest(low, &values).1;
                let remaining_outside_sum =
                    outside.smallest(outside_count - low, &values).1;
                total_sum - removed_sum - remaining_outside_sum
            };
            answer = answer.max(candidate);

            let entering = start + length;
            if entering < n {
                inside.add(ranks[start], nums[start], -1);
                outside.add(ranks[start], nums[start], 1);
                outside.add(ranks[entering], nums[entering], -1);
                inside.add(ranks[entering], nums[entering], 1);
                window_sum += nums[entering] as i64 - nums[start] as i64;
            }
        }

        answer
    }
}