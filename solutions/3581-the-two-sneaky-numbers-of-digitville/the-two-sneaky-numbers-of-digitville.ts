function getSneakyNumbers(nums: number[]): number[] {
    const res: number[] = [];
    const count = new Map<number, number>();
    for (const x of nums) {
        count.set(x, (count.get(x) || 0) + 1);
        if (count.get(x) === 2) {
            res.push(x);
        }
    }
    return res;
}