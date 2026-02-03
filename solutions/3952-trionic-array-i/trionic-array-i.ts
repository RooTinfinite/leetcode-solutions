function isTrionic(nums: number[]): boolean {
    const n = nums.length;
    let i = 1;

    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    const p = i - 1;

    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    const q = i - 1;

    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    const flag = i - 1;

    return p !== 0 && q !== p && flag === n - 1 && flag !== q;
}