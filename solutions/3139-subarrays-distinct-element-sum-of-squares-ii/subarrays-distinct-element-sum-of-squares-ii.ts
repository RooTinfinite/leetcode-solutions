class BIT {
    size: number;
    _tree1: Float64Array;
    _tree2: Float64Array;

    constructor(n: number) {
        this.size = n;
        this._tree1 = new Float64Array(n + 2);
        this._tree2 = new Float64Array(n + 2);
    }

    _lowbit(index: number): number {
        return index & -index;
    }

    add(left: number, right: number, delta: number): void {
        this._add(left, delta);
        this._add(right + 1, -delta);
    }

    query(left: number, right: number): number {
        return this._query(right) - this._query(left - 1);
    }

    _add(index: number, delta: number): void {
        index += 1;
        let rawIndex = index;
        while (index <= this.size) {
            this._tree1[index] += delta;
            this._tree2[index] += rawIndex * delta;
            index += this._lowbit(index);
        }
    }

    _query(index: number): number {
        index += 1;
        let rawIndex = index + 1;
        if (index > this.size) {
            index = this.size;
        }
        let res = 0;
        while (index > 0) {
            res += rawIndex * this._tree1[index] - this._tree2[index];
            index -= this._lowbit(index);
        }
        return res;
    }
}

function sumCounts(A: number[]): number {
    let n = A.length;
    let res = 0n,
        cur = 0n;
    let bit = new BIT(n + 10);
    let seen = new Map<number, number>();
    let mod = 1000000007n;
    for (let i = 0; i < n; i++) {
        let a = A[i];
        let j = (seen.has(a) ? seen.get(a)! : -1) + 1;
        let q = BigInt(bit.query(j, i));
        cur = (cur + q * 2n + BigInt(i - j + 1)) % mod;
        res = (res + cur) % mod;
        bit.add(j, i, 1);
        seen.set(a, i);
    }
    return Number(res);
}