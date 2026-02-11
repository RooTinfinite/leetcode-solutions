class LazyTag {
    toAdd: number = 0;

    add(other: LazyTag): LazyTag {
        this.toAdd += other.toAdd;
        return this;
    }

    hasTag(): boolean {
        return this.toAdd !== 0;
    }

    clear(): void {
        this.toAdd = 0;
    }
}

class SegmentTreeNode {
    minValue: number = 0;
    maxValue: number = 0;
    // int data = 0; // only leaf nodes are used, this question does not require it.
    lazyTag: LazyTag = new LazyTag();
}

class SegmentTree {
    n: number;
    tree: SegmentTreeNode[];

    constructor(data: number[]) {
        this.n = data.length;
        this.tree = new Array(this.n * 4 + 1)
            .fill(null)
            .map(() => new SegmentTreeNode());
        this.build(data, 1, this.n, 1);
    }

    add(l: number, r: number, val: number): void {
        const tag = new LazyTag();
        tag.toAdd = val;
        this.update(l, r, tag, 1, this.n, 1);
    }

    findLast(start: number, val: number): number {
        if (start > this.n) {
            return -1;
        }
        return this.find(start, this.n, val, 1, this.n, 1);
    }

    private applyTag(i: number, tag: LazyTag): void {
        this.tree[i].minValue += tag.toAdd;
        this.tree[i].maxValue += tag.toAdd;
        this.tree[i].lazyTag.add(tag);
    }

    private pushdown(i: number): void {
        if (this.tree[i].lazyTag.hasTag()) {
            const tag = new LazyTag();
            tag.toAdd = this.tree[i].lazyTag.toAdd;
            this.applyTag(i << 1, tag);
            this.applyTag((i << 1) | 1, tag);
            this.tree[i].lazyTag.clear();
        }
    }

    private pushup(i: number): void {
        this.tree[i].minValue = Math.min(
            this.tree[i << 1].minValue,
            this.tree[(i << 1) | 1].minValue,
        );
        this.tree[i].maxValue = Math.max(
            this.tree[i << 1].maxValue,
            this.tree[(i << 1) | 1].maxValue,
        );
    }

    private build(data: number[], l: number, r: number, i: number): void {
        if (l == r) {
            this.tree[i].minValue = this.tree[i].maxValue = data[l - 1];
            return;
        }

        const mid = l + ((r - l) >> 1);
        this.build(data, l, mid, i << 1);
        this.build(data, mid + 1, r, (i << 1) | 1);

        this.pushup(i);
    }
    private update(
        targetL: number,
        targetR: number,
        tag: LazyTag,
        l: number,
        r: number,
        i: number,
    ): void {
        if (targetL <= l && r <= targetR) {
            this.applyTag(i, tag);
            return;
        }

        this.pushdown(i);
        const mid = l + ((r - l) >> 1);
        if (targetL <= mid) this.update(targetL, targetR, tag, l, mid, i << 1);
        if (targetR > mid)
            this.update(targetL, targetR, tag, mid + 1, r, (i << 1) | 1);
        this.pushup(i);
    }

    private find(
        targetL: number,
        targetR: number,
        val: number,
        l: number,
        r: number,
        i: number,
    ): number {
        if (this.tree[i].minValue > val || this.tree[i].maxValue < val) {
            return -1;
        }

        // according to the Intermediate Value Theorem, there must be a solution within this interval.
        if (l == r) {
            return l;
        }

        this.pushdown(i);
        const mid = l + ((r - l) >> 1);

        // targetL is definitely less than or equal to r (=n)
        if (targetR >= mid + 1) {
            const res = this.find(
                targetL,
                targetR,
                val,
                mid + 1,
                r,
                (i << 1) | 1,
            );
            if (res != -1) return res;
        }

        if (l <= targetR && mid >= targetL) {
            return this.find(targetL, targetR, val, l, mid, i << 1);
        }

        return -1;
    }
}

function longestBalanced(nums: number[]): number {
    const occurrences = new Map<number, Queue<number>>();
    const sgn = (x: number) => (x % 2 == 0 ? 1 : -1);

    let len = 0;
    const prefixSum: number[] = new Array(nums.length).fill(0);

    prefixSum[0] = sgn(nums[0]);
    if (!occurrences.has(nums[0])) occurrences.set(nums[0], new Queue());
    occurrences.get(nums[0])!.push(1);

    for (let i = 1; i < nums.length; i++) {
        prefixSum[i] = prefixSum[i - 1];
        if (!occurrences.has(nums[i])) occurrences.set(nums[i], new Queue());
        const occ = occurrences.get(nums[i])!;
        if (occ.size() === 0) {
            prefixSum[i] += sgn(nums[i]);
        }
        occ.push(i + 1);
    }

    const seg = new SegmentTree(prefixSum);

    for (let i = 0; i < nums.length; i++) {
        len = Math.max(len, seg.findLast(i + len, 0) - i);

        let nextPos = nums.length + 1;
        const occ = occurrences.get(nums[i])!;
        occ.pop();
        if (occ.size() > 0) {
            nextPos = occ.front();
        }

        seg.add(i + 1, nextPos - 1, -sgn(nums[i]));
    }

    return len;
}