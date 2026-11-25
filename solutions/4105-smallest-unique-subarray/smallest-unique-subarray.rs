impl Solution {
    pub fn smallest_unique_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        let mut sa: Vec<usize> = (0..n).collect();
        let mut rank: Vec<usize> = nums.iter().map(|&x| x as usize).collect();
        let mut next_rank = vec![0_usize; n];

        // Construct the sorted suffix array by doubling
        let mut max_rank = rank.iter().copied().max().unwrap();
        let mut temp = vec![0_usize; n];
        let mut cnt = vec![0_usize; (n + 1).max(max_rank + 2)];

        fn counting_sort<F: Fn(usize) -> usize>(
            sa: &mut Vec<usize>,
            temp: &mut Vec<usize>,
            cnt: &mut [usize],
            max_rank: usize,
            get_key: F,
        ) {
            cnt[..max_rank + 2].fill(0);

            for &i in sa.iter() {
                cnt[get_key(i)] += 1;
            }

            for i in 1..=max_rank + 1 {
                cnt[i] += cnt[i - 1];
            }

            for p in (0..sa.len()).rev() {
                let i = sa[p];
                let key = get_key(i);
                cnt[key] -= 1;
                temp[cnt[key]] = i;
            }

            std::mem::swap(sa, temp);
        }

        let mut k = 1;
        while k < n {
            // Sort by the second key, then stably sort by the first key
            counting_sort(&mut sa, &mut temp, &mut cnt, max_rank, |i| {
                if i + k < n { rank[i + k] + 1 } else { 0 }
            });
            counting_sort(&mut sa, &mut temp, &mut cnt, max_rank, |i| {
                rank[i] + 1
            });

            next_rank[sa[0]] = 0;

            // Assign ranks to the newly sorted suffixes
            for i in 1..n {
                let (x, y) = (sa[i - 1], sa[i]);
                let rx = if x + k < n { rank[x + k] + 1 } else { 0 };
                let ry = if y + k < n { rank[y + k] + 1 } else { 0 };

                next_rank[y] = next_rank[x] + usize::from(rank[x] != rank[y] || rx != ry);
            }

            std::mem::swap(&mut rank, &mut next_rank);
            max_rank = rank[sa[n - 1]];

            // All n suffixes have distinct ranks, so sorting is complete
            if max_rank == n - 1 {
                break;
            }

            k <<= 1;
        }

        // Construct LCP using Kasai's algorithm
        let mut pos = vec![0_usize; n];
        let mut lcp = vec![0_usize; n];
        for (i, &index) in sa.iter().enumerate() {
            pos[index] = i;
        }

        let mut h = 0;
        for i in 0..n {
            if pos[i] == 0 {
                h = 0;
                continue;
            }

            let j = sa[pos[i] - 1];
            while i + h < n && j + h < n && nums[i + h] == nums[j + h] {
                h += 1;
            }

            lcp[pos[i]] = h;

            if h > 0 {
                h -= 1;
            }
        }

        let mut answer = n;
        for i in 0..n {
            let next = if i + 1 < n { lcp[i + 1] } else { 0 };

            let need = lcp[i].max(next) + 1;
            if sa[i] + need <= n {
                answer = answer.min(need);
            }
        }

        answer as i32
    }
}