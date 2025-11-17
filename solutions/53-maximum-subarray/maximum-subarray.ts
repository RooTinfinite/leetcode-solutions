function maxSubArray(nums: number[]): number {
    // Our helper function is designed to solve this problem for
    // any array - so just call it using the entire input!
    return findBestSubarray(nums, 0, nums.length - 1);
}
function findBestSubarray(nums: number[], left: number, right: number): number {
    // Base case - empty array.
    if (left > right) {
        return -Infinity;
    }
    let mid = Math.floor((left + right) / 2);
    let curr = 0;
    let bestLeftSum = 0;
    let bestRightSum = 0;
    // Iterate from the middle to the beginning.
    for (let i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeftSum = Math.max(bestLeftSum, curr);
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0;
    for (let i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRightSum = Math.max(bestRightSum, curr);
    }
    // The bestCombinedSum uses the middle element and the best possible sum from each half.
    let bestCombinedSum = nums[mid] + bestLeftSum + bestRightSum;
    // Find the best subarray possible from both halves.
    let leftHalf = findBestSubarray(nums, left, mid - 1);
    let rightHalf = findBestSubarray(nums, mid + 1, right);
    // The largest of the 3 is the answer for any given input array.
    return Math.max(bestCombinedSum, Math.max(leftHalf, rightHalf));
}