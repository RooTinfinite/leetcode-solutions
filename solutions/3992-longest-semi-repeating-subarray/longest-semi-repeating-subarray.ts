function longestSubarray(nums: number[], k: number): number {
    const n: number = nums.length;
    let repeating: number = 0;
    let left: number = 0;
    const d: Map<number, number> = new Map();

    for (const num of nums) {
        d.set(num, (d.get(num) || 0) + 1);

        if (d.get(num) === 2) {
            repeating += 1;
        }

        if (repeating > k) {
            const leftNum = nums[left];
            d.set(leftNum, d.get(leftNum)! - 1);

            if (d.get(leftNum) === 1) {
                repeating -= 1;
            }

            left += 1;
        }
    }

    return n - left;
}