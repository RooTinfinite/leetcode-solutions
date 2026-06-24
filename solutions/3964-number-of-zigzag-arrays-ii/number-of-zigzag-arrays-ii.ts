const MOD = 1_000_000_007n;

class Matrix {
    data: BigInt64Array;

    constructor(
        public n: number,
        public m: number,
    ) {
        this.data = new BigInt64Array(n * m);
    }

    get(i: number, j: number): bigint {
        return this.data[i * this.m + j];
    }

    set(i: number, j: number, val: bigint) {
        this.data[i * this.m + j] = val;
    }

    mul(b: Matrix): Matrix {
        const res = new Matrix(this.n, b.m);

        for (let i = 0; i < this.n; i++) {
            for (let k = 0; k < this.m; k++) {
                const r = this.get(i, k);
                if (r === 0n) continue;

                for (let j = 0; j < b.m; j++) {
                    res.set(i, j, (res.get(i, j) + r * b.get(k, j)) % MOD);
                }
            }
        }
        return res;
    }

    powMul(exp: bigint, res: Matrix): Matrix {
        let base = new Matrix(this.n, this.m);
        base.data = new BigInt64Array(this.data);

        while (exp > 0n) {
            if ((exp & 1n) === 1n) {
                res = res.mul(base);
            }
            base = base.mul(base);
            exp >>= 1n;
        }

        return res;
    }
}

function zigZagArrays(n: number, l: number, r: number): number {
    const m = r - l + 1;
    if (n === 1) return m;

    let u = new Matrix(2 * m, 2 * m);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < i; j++) {
            u.set(i, j + m, 1n);
        }
        for (let j = i + 1; j < m; j++) {
            u.set(i + m, j, 1n);
        }
    }

    let dp = new Matrix(1, 2 * m);
    for (let i = 0; i < 2 * m; i++) {
        dp.set(0, i, 1n);
    }

    dp = u.powMul(BigInt(n - 1), dp);

    let ans = 0n;
    for (let i = 0; i < 2 * m; i++) {
        ans = (ans + dp.get(0, i)) % MOD;
    }

    return Number(ans);
}