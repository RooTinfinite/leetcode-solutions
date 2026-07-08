const n = 100004;
const sieve = new Uint8Array(n);
sieve[0] = sieve[1] = 1;

for (let i = 2; i <= 316; i++)
    if (!sieve[i])
        for (let j = i * i; j < n; j += i)
            sieve[j] = 1;

const minOperations = nums => {
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        let j = nums[i];
        if (i & 1)
            while (!sieve[j++])
                res++;
        else
            while (sieve[j++])
                res++;
    }

    return res;
};