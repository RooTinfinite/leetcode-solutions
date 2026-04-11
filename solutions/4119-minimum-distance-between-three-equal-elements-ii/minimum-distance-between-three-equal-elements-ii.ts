function minimumDistance(nums: number[]): number {
    const next = Array.from<number>({ length: nums.length }).fill(-1);
    const occur = new Map<number, number>();
    let ans = nums.length + 1;

    for (let i = nums.length - 1; i >= 0; i--) {
        if (occur.has(nums[i])) {
            next[i] = occur.get(nums[i])!;
        }
        occur.set(nums[i], i);
    }

    for (let i = 0; i < nums.length; i++) {
        let secondPos = next[i];
        let thirdPos = next[secondPos];
        if (secondPos !== -1 && thirdPos !== -1) {
            ans = Math.min(ans, thirdPos - i);
        }
    }

    if (ans === nums.length + 1) {
        return -1;
    } else {
        return ans * 2;
    }
}