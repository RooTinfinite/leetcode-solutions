function maxDifference(s: string, k: number): number {
    const n = s.length;
    let ans = -Infinity;

    const getStatus = (cnt_a: number, cnt_b: number): number => {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    for (const a of ["0", "1", "2", "3", "4", "5"]) {
        for (const b of ["0", "1", "2", "3", "4", "5"]) {
            if (a === b) {
                continue;
            }
            const best: number[] = [Infinity, Infinity, Infinity, Infinity];
            let cnt_a = 0,
                cnt_b = 0;
            let prev_a = 0,
                prev_b = 0;
            let left = -1;
            for (let right = 0; right < n; right++) {
                cnt_a += s[right] === a ? 1 : 0;
                cnt_b += s[right] === b ? 1 : 0;

                while (right - left >= k && cnt_b - prev_b >= 2) {
                    const left_status = getStatus(prev_a, prev_b);
                    best[left_status] = Math.min(
                        best[left_status],
                        prev_a - prev_b,
                    );
                    left++;
                    prev_a += s[left] === a ? 1 : 0;
                    prev_b += s[left] === b ? 1 : 0;
                }

                const right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] !== Infinity) {
                    ans = Math.max(
                        ans,
                        cnt_a - cnt_b - best[right_status ^ 0b10],
                    );
                }
            }
        }
    }
    return ans;
}