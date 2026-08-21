impl Solution {
    pub fn find_kth_smallest(mut coins: Vec<i32>, k: i32) -> i64 {
        fn gcd(mut a: i64, mut b: i64) -> i64 {
            while b != 0 {
                (a, b) = (b, a % b);
            }
            a
        }

        coins.sort_unstable();

        let mut new_coins = Vec::new();

        for x in coins {
            let mut flag = true;

            for &y in &new_coins {
                if x % y == 0 {
                    flag = false;
                    break;
                }
            }

            if flag {
                new_coins.push(x);
            }
        }

        let coins = new_coins;

        let n = coins.len();
        let m = 1usize << n;
        let mut lcm = vec![1i64; m];

        let mut left = k as i64;
        let mut right = coins[0] as i64 * k as i64 + 1;

        for mask in 1..m {
            let pre_mask = mask & (mask - 1);
            let i = mask.trailing_zeros() as usize;
            let coin = coins[i] as i64;

            let tmp = lcm[pre_mask] / gcd(lcm[pre_mask], coin);

            if tmp <= right / coin {
                lcm[mask] = tmp * coin;
            } else {
                lcm[mask] = right + 1;
            }
        }

        let get = |x: i64| -> i64 {
            let mut count = 0i64;

            for mask in 1..m {
                if lcm[mask] > x {
                    continue;
                }

                if mask.count_ones() & 1 == 1 {
                    count += x / lcm[mask];
                } else {
                    count -= x / lcm[mask];
                }
            }

            count
        };

        while left < right {
            let mid = (left + right) / 2;

            if get(mid) >= k as i64 {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left
    }
}