const threeSum = (nums: number[]): number[][] => {
    const res = new Set<string>();
    const dups = new Set<number>();
    const seen = new Map<number, number>();
    for (let i = 0; i < nums.length; ++i)
        if (!dups.has(nums[i])) {
            dups.add(nums[i]);
            for (let j = i + 1; j < nums.length; ++j) {
                const complement = -nums[i] - nums[j];
                if (seen.has(complement) && seen.get(complement) === i) {
                    const triplet = [nums[i], nums[j], complement].sort(
                        (a, b) => a - b,
                    );
                    res.add(JSON.stringify(triplet));
                }
                seen.set(nums[j], i);
            }
        }
    return Array.from(res).map((text) => JSON.parse(text));
};