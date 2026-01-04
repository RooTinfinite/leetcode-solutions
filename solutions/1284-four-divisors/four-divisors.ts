function sumFourDivisors(nums: number[]): number {
    let ans = 0;

    for (const x of nums) {
        let n = x, p = 0, q = 0, cnt = 0;

        for (let i = 2; i * i <= n && cnt <= 2; i++) {
            if (n % i === 0) {
                cnt++;
                if (cnt === 1) p = i;
                else q = i;
                while (n % i === 0) n /= i;
            }
        }

        if (n > 1) {
            cnt++;
            if (cnt === 1) p = n;
            else q = n;
        }

        if (cnt === 2 && p * q === x)
            ans += 1 + p + q + x;
        else if (cnt === 1 && p * p * p === x)
            ans += 1 + p + p * p + x;
    }

    return ans;
}