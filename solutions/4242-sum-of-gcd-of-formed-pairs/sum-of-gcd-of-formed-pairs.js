var gcdSum = function (nums) {
    const gcd = (a, b) => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return a;
    };

    const n = nums.length;
    const mx = new Array(n);
    let prefixMax = -Infinity;
    for (let i = 0; i < n; i++) {
        prefixMax = Math.max(prefixMax, nums[i]);
        mx[i] = prefixMax;
    }

    const prefixGcd = new Array(n);
    for (let i = 0; i < n; i++) {
        prefixGcd[i] = gcd(nums[i], mx[i]);
    }

    prefixGcd.sort((a, b) => a - b);
    let ans = 0;
    let left = 0,
        right = n - 1;
    while (left < right) {
        ans += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return ans;
};