use std::cmp::{min, max};

impl Solution {
    pub fn earliest_and_latest(n: i32, first_player: i32, second_player: i32) -> Vec<i32> {
        const MAX_N: usize = 30;
        let mut f = [[[0; MAX_N]; MAX_N]; MAX_N];
        let mut g = [[[0; MAX_N]; MAX_N]; MAX_N];
        
        let mut first = first_player as usize;
        let mut second = second_player as usize;
        if first > second {
            std::mem::swap(&mut first, &mut second);
        }
        let (earliest, latest) = Self::dp(n as usize, first, second, &mut f, &mut g);
        vec![earliest, latest]
    }

    fn dp(n: usize, first: usize, second: usize, f: &mut [[[i32; 30]; 30]; 30], g: &mut [[[i32; 30]; 30]; 30]) -> (i32, i32) {
        if f[n][first][second] != 0 {
            return (f[n][first][second], g[n][first][second]);
        }
        
        if first + second == n + 1 {
            return (1, 1);
        }
        
        // Symmetric situation handling
        if first + second > n + 1 {
            let (x, y) = Self::dp(n, n + 1 - second, n + 1 - first, f, g);
            f[n][first][second] = x;
            g[n][first][second] = y;
            return (x, y);
        }

        let mut earliest = i32::MAX;
        let mut latest = i32::MIN;
        let n_half = (n + 1) / 2;
        if second <= n_half {
            // All on the left or center
            for i in 0..first {
                for j in 0..(second - first) {
                    let (x, y) = Self::dp(n_half, i + 1, i + j + 2, f, g);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        } else {
            // second on the right
            let s_prime = n + 1 - second;
            let mid = (n - 2 * s_prime + 1) / 2;
            for i in 0..first {
                for j in 0..(s_prime - first) {
                    let (x, y) = Self::dp(n_half, i + 1, i + j + mid + 2, f, g);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }
        f[n][first][second] = earliest + 1;
        g[n][first][second] = latest + 1;
        (f[n][first][second], g[n][first][second])
    }
}