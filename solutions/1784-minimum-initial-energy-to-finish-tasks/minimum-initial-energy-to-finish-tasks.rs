impl Solution {
    pub fn minimum_effort(mut tasks: Vec<Vec<i32>>) -> i32 {
        tasks.sort_by(|a, b| (b[1] - b[0]).cmp(&(a[1] - a[0])));
        let mut ans = 0;
        let mut remain = 0;
        for task in tasks.iter() {
            if remain <= task[1] {
                ans += task[1] - remain;
            }
            remain = std::cmp::max(task[1] - task[0], remain - task[0]);
        }
        ans
    }
}