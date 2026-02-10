function longestBalanced(nums: number[]): number {
    let len = 0;

    for (let i = 0; i < nums.length; i++) {
        const odd = new Map<number, number>();
        const even = new Map<number, number>();

        for (let j = i; j < nums.length; j++) {
            const c = nums[j] & 1 ? odd : even;

            c.set(nums[j], (c.get(nums[j]) ?? 0) + 1);

            if (odd.size == even.size) {
                len = Math.max(len, j - i + 1);
            }
        }
    }

    return len;
}