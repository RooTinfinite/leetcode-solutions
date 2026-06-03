impl Solution {
    fn solve(start1: &Vec<i32>, duration1: &Vec<i32>, start2: &Vec<i32>, duration2: &Vec<i32>) -> i32 {
        let mut finish1 = i32::MAX;
        for i in 0..start1.len() {
            finish1 = finish1.min(start1[i] + duration1[i]);
        }
        let mut finish2 = i32::MAX;
        for i in 0..start2.len() {
            finish2 = finish2.min(start2[i].max(finish1) + duration2[i]);
        }
        finish2
    }

    pub fn earliest_finish_time(land_start_time: Vec<i32>, land_duration: Vec<i32>, water_start_time: Vec<i32>, water_duration: Vec<i32>) -> i32 {
        let land_water = Self::solve(&land_start_time, &land_duration, &water_start_time, &water_duration);
        let water_land = Self::solve(&water_start_time, &water_duration, &land_start_time, &land_duration);
        land_water.min(water_land)
    }
}