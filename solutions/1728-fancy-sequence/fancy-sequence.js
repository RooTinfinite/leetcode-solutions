const MOD = 1000000007n;

var Fancy = function () {
    this.v = [];
    this.a = [1n];
    this.b = [0n];
};

Fancy.prototype.append = function (val) {
    this.v.push(BigInt(val));
    this.a.push(this.a[this.a.length - 1]);
    this.b.push(this.b[this.b.length - 1]);
};

Fancy.prototype.addAll = function (inc) {
    const lastIdx = this.b.length - 1;
    this.b[lastIdx] = (this.b[lastIdx] + BigInt(inc)) % MOD;
};

Fancy.prototype.multAll = function (m) {
    const lastIdx = this.a.length - 1;
    const mBigInt = BigInt(m);
    this.a[lastIdx] = (this.a[lastIdx] * mBigInt) % MOD;
    this.b[lastIdx] = (this.b[lastIdx] * mBigInt) % MOD;
};

// fast exponentiation（返回bigint）
Fancy.prototype.quickMul = function (x, y) {
    let ret = 1n;
    let cur = BigInt(x);
    let power = BigInt(y);
    while (power !== 0n) {
        if ((power & 1n) !== 0n) {
            ret = (ret * cur) % MOD;
        }
        cur = (cur * cur) % MOD;
        power >>= 1n;
    }
    return ret;
};

// multiplicative inverse（返回bigint）
Fancy.prototype.inv = function (x) {
    return this.quickMul(x, MOD - 2n);
};

Fancy.prototype.getIndex = function (idx) {
    if (idx >= this.v.length) {
        return -1;
    }

    const ao =
        (this.inv(Number(this.a[idx])) * this.a[this.a.length - 1]) % MOD;
    const bo =
        (this.b[this.b.length - 1] - ((this.b[idx] * ao) % MOD) + MOD) % MOD;
    const ans = (((ao * this.v[idx]) % MOD) + bo) % MOD;

    return Number(ans);
};