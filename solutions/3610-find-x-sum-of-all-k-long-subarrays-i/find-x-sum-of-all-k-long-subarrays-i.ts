function findXSum(nums: number[], k: number, x: number): number[] {
    const n: number = nums.length;
    const ans: number[] = [];

    for (let i = 0; i <= n - k; i++) {
        const cnt: Map<number, number> = new Map();
        for (let j = i; j < i + k; j++) {
            cnt.set(nums[j], (cnt.get(nums[j]) || 0) + 1);
        }

        const freq: [number, number][] = Array.from(cnt.entries()).map(
            ([num, count]) => [count, num],
        );
        freq.sort((a, b) => (b[0] !== a[0] ? b[0] - a[0] : b[1] - a[1]));
        let xsum: number = 0;
        for (let j = 0; j < x && j < freq.length; j++) {
            xsum += freq[j][0] * freq[j][1];
        }
        ans.push(xsum);
    }

    return ans;
}