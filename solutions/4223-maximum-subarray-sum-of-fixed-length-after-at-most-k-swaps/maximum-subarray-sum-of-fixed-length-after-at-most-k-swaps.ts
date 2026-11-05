function maxSum(nums: number[], length: number, k: number): number {
    const n = nums.length;
    let windowSum = 0;
    for (let i = 0; i < length; i++) {
        windowSum += nums[i];
    }

    if (length === n) return windowSum;

    if (k === 0) {
        let best = windowSum;
        for (let i = length; i < n; i++) {
            windowSum += nums[i] - nums[i - length];
            best = Math.max(best, windowSum);
        }
        return best;
    }

    const order = Array.from({ length: n }, (_, i) => i);
    order.sort((a, b) => nums[b] - nums[a]);

    let upperBound = 0;
    for (let i = 0; i < length; i++) {
        upperBound += nums[order[i]];
    }

    if (k >= Math.min(length, n - length)) return upperBound;

    let best = -Infinity;

    for (let start = 0; start + length <= n; start++) {
        const end = start + length;
        let outside = 0;
        let selected = 0;
        let sum = 0;

        // Select the largest values, using at most k indices outside the window.
        for (const index of order) {
            if (index < start || index >= end) {
                if (outside === k) continue;
                outside++;
            }

            sum += nums[index];
            if (++selected === length) break;
        }

        best = Math.max(best, sum);
        if (best === upperBound) return best;
    }

    return best;
};