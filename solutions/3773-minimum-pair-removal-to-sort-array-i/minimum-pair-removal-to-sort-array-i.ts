function minimumPairRemoval(nums: number[]): number {
    let count = 0;

    while (nums.length > 1) {
        let isAscending = true;
        let minSum = Infinity;
        let targetIndex = -1;

        for (let i = 0; i < nums.length - 1; i++) {
            const sum = nums[i] + nums[i + 1];

            if (nums[i] > nums[i + 1]) {
                isAscending = false;
            }

            if (sum < minSum) {
                minSum = sum;
                targetIndex = i;
            }
        }

        if (isAscending) {
            break;
        }

        count++;
        nums[targetIndex] = minSum;
        nums.splice(targetIndex + 1, 1);
    }

    return count;
}