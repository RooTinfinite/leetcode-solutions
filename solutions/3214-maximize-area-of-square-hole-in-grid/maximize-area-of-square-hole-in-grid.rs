use std::cmp;

impl Solution {
    pub fn maximize_square_hole_area(n: i32, m: i32, mut h_bars: Vec<i32>, mut v_bars: Vec<i32>) -> i32 {
        h_bars.sort_unstable();
        v_bars.sort_unstable();
        let mut hmax = 1;
        let mut vmax = 1;
        let mut hcur = 1;
        let mut vcur = 1;
        for i in 1..h_bars.len() {
            if h_bars[i] == h_bars[i - 1] + 1 {
                hcur += 1;
            } else {
                hcur = 1;
            }
            hmax = cmp::max(hmax, hcur);
        }
        for i in 1..v_bars.len() {
            if v_bars[i] == v_bars[i - 1] + 1 {
                vcur += 1;
            } else {
                vcur = 1;
            }
            vmax = cmp::max(vmax, vcur);
        }
        let side = cmp::min(hmax, vmax) + 1;
        side * side
    }
}