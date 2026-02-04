/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSumTrionic = function(nums) {
    const n = nums.length;
    let res = -Infinity;

    for (let i = 1; i < n - 2; ) {
        let a = i, b = i;
        let net = BigInt(nums[a]);

        // Middle decreasing part
        while (b + 1 < n && nums[b + 1] < nums[b]) {
            net += BigInt(nums[++b]);
        }
        if (b === a) { i++; continue; }

        let c = b;
        let left = 0n, right = 0n;
        let lx = -BigInt(1e16), rx = -BigInt(1e16);

        // Left increasing part
        while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
            left += BigInt(nums[--a]);
            if (left > lx) lx = left;
        }
        if (a === i) { i++; continue; }

        // Right increasing part
        while (b + 1 < n && nums[b + 1] > nums[b]) {
            right += BigInt(nums[++b]);
            if (right > rx) rx = right;
        }
        if (b === c) { i++; continue; }

        let currentSum = Number(lx + rx + net);
        if (currentSum > res) res = currentSum;
        
        i = b;
    }
    return res;
};