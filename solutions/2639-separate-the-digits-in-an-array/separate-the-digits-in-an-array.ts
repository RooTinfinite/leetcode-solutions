function separateDigits(nums: number[]): number[] {
    const res: number[] = [];
    for (let i = nums.length - 1; i >= 0; i--) {
        let x = nums[i];
        while (x > 0) {
            res.push(x % 10);
            x = Math.floor(x / 10);
        }
    }
    res.reverse();
    return res;
}