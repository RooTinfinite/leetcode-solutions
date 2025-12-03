function sortColors(nums: number[]): void {
    /*
    Dutch National Flag problem solution.
    */
    let p0 = 0,
        curr = 0;
    let p2 = nums.length - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            [nums[curr++], nums[p0++]] = [nums[p0], nums[curr]];
        } else if (nums[curr] == 2) {
            [nums[curr], nums[p2--]] = [nums[p2], nums[curr]];
        } else curr++;
    }
}