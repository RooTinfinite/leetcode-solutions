const MOD = 1000000007n;

class Fancy {
    private v: bigint[];
    private a: bigint[];
    private b: bigint[];

    constructor() {
        this.v = [];
        this.a = [1n];
        this.b = [0n];
    }

    // 添加值
    append(val: number): void {
        this.v.push(BigInt(val));
        this.a.push(this.a[this.a.length - 1]);
        this.b.push(this.b[this.b.length - 1]);
    }

    // 增加所有值
    addAll(inc: number): void {
        const lastIdx = this.b.length - 1;
        this.b[lastIdx] = (this.b[lastIdx] + BigInt(inc)) % MOD;
    }

    // 乘以所有值
    multAll(m: number): void {
        const lastIdx = this.a.length - 1;
        const mBigInt = BigInt(m);
        this.a[lastIdx] = (this.a[lastIdx] * mBigInt) % MOD;
        this.b[lastIdx] = (this.b[lastIdx] * mBigInt) % MOD;
    }

    // fast exponentiation（使用bigint）
    private quickMul(x: bigint, y: bigint): bigint {
        let ret = 1n;
        let cur = x;
        let power = y;

        while (power !== 0n) {
            if ((power & 1n) !== 0n) {
                ret = (ret * cur) % MOD;
            }
            cur = (cur * cur) % MOD;
            power >>= 1n;
        }
        return ret;
    }

    // multiplicative inverse（使用费马小定理）
    private inv(x: bigint): bigint {
        return this.quickMul(x, MOD - 2n);
    }

    // 获取索引处的值
    getIndex(idx: number): number {
        if (idx >= this.v.length) {
            return -1;
        }

        const ao = (this.inv(this.a[idx]) * this.a[this.a.length - 1]) % MOD;
        const bo =
            (this.b[this.b.length - 1] - ((this.b[idx] * ao) % MOD) + MOD) %
            MOD;
        const ans = (((ao * this.v[idx]) % MOD) + bo) % MOD;
        return Number(ans);
    }
}