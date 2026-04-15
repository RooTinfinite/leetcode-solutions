function findMissingRanges(
    nums: number[],
    lower: number,
    upper: number,
): number[][] {
    let n = nums.length;
    let missingRanges: number[][] = [];
    if (n === 0) {
        missingRanges.push([lower, upper]);
        return missingRanges;
    }

    // Check for any missing numbers between the lower bound and nums[0].
    if (lower < nums[0]) {
        missingRanges.push([lower, nums[0] - 1]);
    }

    // Check for any missing numbers between successive elements of nums.
    for (let i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= 1) {
            continue;
        }
        missingRanges.push([nums[i] + 1, nums[i + 1] - 1]);
    }

    // Check for any missing numbers between the last element of nums and the upper bound.
    if (upper > nums[n - 1]) {
        missingRanges.push([nums[n - 1] + 1, upper]);
    }

    return missingRanges;
}