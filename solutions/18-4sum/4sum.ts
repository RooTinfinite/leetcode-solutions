function fourSum(nums: number[], target: number): number[][] {
    function twoSum(start: number, target: number): number[][] {
        let res = [];
        let s = new Set<number>();
        for (let i = start; i < nums.length; i++) {
            if (res.length == 0 || res[res.length - 1][1] != nums[i]) {
                if (s.has(target - nums[i])) {
                    res.push([target - nums[i], nums[i]]);
                }
            }
            s.add(nums[i]);
        }
        return res;
    }
    function kSum(start: number, target: number, k: number): number[][] {
        let res = [];
        // If we have run out of numbers to add, return res.
        if (start === nums.length) {
            return res;
        }
        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        let averageValue = Math.floor(target / k);
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (
            nums[start] > averageValue ||
            averageValue > nums[nums.length - 1]
        ) {
            return res;
        }
        if (k === 2) {
            return twoSum(start, target);
        }
        for (let i = start; i < nums.length; i++) {
            if (i === start || nums[i - 1] !== nums[i]) {
                kSum(i + 1, target - nums[i], k - 1).forEach((set) => {
                    res.push([nums[i]].concat(set));
                });
            }
        }
        return res;
    }
    nums.sort((a, b) => a - b);
    return kSum(0, target, 4);
}