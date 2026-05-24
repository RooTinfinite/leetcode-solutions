impl Solution {
    pub fn max_jumps(arr: Vec<i32>, d: i32) -> i32 {
        let n = arr.len();
        let mut f = vec![-1; n];
        let d = d as usize;
        
        fn dfs(arr: &Vec<i32>, f: &mut Vec<i32>, id: usize, d: usize, n: usize) {
            if f[id] != -1 {
                return;
            }
            f[id] = 1;
            
            let mut i = id as i32 - 1;
            while i >= 0 && (id as i32 - i) <= d as i32 && arr[id] > arr[i as usize] {
                let i_idx = i as usize;
                dfs(arr, f, i_idx, d, n);
                f[id] = f[id].max(f[i_idx] + 1);
                i -= 1;
            }
            
            for i in id + 1..n {
                if i - id <= d && arr[id] > arr[i] {
                    dfs(arr, f, i, d, n);
                    f[id] = f[id].max(f[i] + 1);
                } else {
                    break;
                }
            }
        }
        
        for i in 0..n {
            dfs(&arr, &mut f, i, d, n);
        }
        
        *f.iter().max().unwrap()
    }
}