function minimumSize(n: number[], maxOps: number): number {
    let low = 1;
    let high = Math.max(...n);
    while (low < high) {
        const mid = (low + high) >> 1;
        let cnt = 0;
        for (const x of n) {
            cnt += ~~((x - 1) / mid);
        }
        if (cnt <= maxOps) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high
};