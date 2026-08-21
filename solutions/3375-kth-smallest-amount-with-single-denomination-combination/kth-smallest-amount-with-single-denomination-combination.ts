function findKthSmallest(coins: number[], k: number): number {
    coins.sort((a, b) => a - b);
    const newCoins: number[] = [];
    for (const x of coins) {
        let flag: boolean = true;
        for (const y of newCoins) {
            if (x % y === 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            newCoins.push(x);
        }
    }
    coins = newCoins;

    const n: number = coins.length;
    const m: number = 1 << n;
    const lcm: bigint[] = new Array(m).fill(0n);
    let l: bigint = BigInt(k);
    let r: bigint = BigInt(coins[0]) * BigInt(k) + 1n;

    const gcd = (a: bigint, b: bigint): bigint => {
        a = a < 0n ? -a : a;
        b = b < 0n ? -b : b;
        while (b !== 0n) {
            [a, b] = [b, a % b];
        }
        return a;
    };

    const trailingZeros = (x: number): number => {
        let count = 0;
        while ((x & 1) === 0) {
            count++;
            x >>= 1;
        }
        return count;
    };

    const popcount = (x: number): number => {
        let count = 0;
        while (x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    };

    lcm[0] = 1n;
    for (let mask = 1; mask < m; mask++) {
        const preMask: number = mask & (mask - 1);
        const i: number = trailingZeros(mask);

        const coin: bigint = BigInt(coins[i]);
        const tmp: bigint = lcm[preMask] / gcd(lcm[preMask], coin);
        if (tmp <= r / coin) {
            lcm[mask] = tmp * coin;
        } else {
            lcm[mask] = r + 1n;
        }
    }

    const count = (x: bigint): bigint => {
        let res: bigint = 0n;
        for (let mask = 1; mask < m; mask++) {
            if (lcm[mask] > x) continue;

            if (popcount(mask) & 1) {
                res += x / lcm[mask];
            } else {
                res -= x / lcm[mask];
            }
        }
        return res;
    };

    while (l < r) {
        const mid: bigint = (l + r) / 2n;
        if (count(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }
    return Number(l);
}