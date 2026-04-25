impl Solution {
    pub fn max_distance(side: i32, points: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut arr: Vec<i64> = Vec::new();
        
        for p in points {
            let x = p[0];
            let y = p[1];
            if x == 0 {
                arr.push(y as i64);
            } else if y == side {
                arr.push(side as i64 + x as i64);
            } else if x == side {
                arr.push(side as i64 * 3 - y as i64);
            } else {
                arr.push(side as i64 * 4 - x as i64);
            }
        }
        
        arr.sort_unstable();
        
        let lower_bound = |target: i64| -> usize {
            let mut left = 0;
            let mut right = arr.len();
            while left < right {
                let mid = left + (right - left) / 2;
                if arr[mid] < target {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            left
        };
        
        let check = |limit: i64| -> bool {
            let perimeter = side as i64 * 4;
            for &start in &arr {
                let end = start + perimeter - limit;
                let mut cur = start;
                for _ in 0..(k - 1) {
                    let idx = lower_bound(cur + limit);
                    if idx == arr.len() || arr[idx] > end {
                        cur = -1;
                        break;
                    }
                    cur = arr[idx];
                }
                if cur >= 0 {
                    return true;
                }
            }
            false
        };
        
        let mut lo = 1i64;
        let mut hi = side as i64;
        let mut ans = 0;
        
        while lo <= hi {
            let mid = (lo + hi) / 2;
            if check(mid) {
                lo = mid + 1;
                ans = mid as i32;
            } else {
                hi = mid - 1;
            }
        }
        
        ans
    }
}