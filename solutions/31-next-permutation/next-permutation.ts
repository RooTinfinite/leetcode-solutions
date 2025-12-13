function nextPermutation(nums: number[]): void {
    let i = nums.length - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        let j = nums.length - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, i + 1);
    function reverse(nums: number[], start: number): void {
        let i = start,
            j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    function swap(nums: number[], i: number, j: number): void {
        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}