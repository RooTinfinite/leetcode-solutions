function minElement(nums) {
    let ans = 37;
    for (const num of nums) {
        let dig = 0;
        let n = num;
        while (n > 0) {
            dig += n % 10;
            n = Math.floor(n / 10);
        }
        ans = Math.min(ans, dig);
    }
    return ans;
}