import { AvlTree } from "@datastructures-js/binary-search-tree";

type Entry = [number, number];

function getCosts(nums: number[], x: number): number[] {
    const n = nums.length;
    const ops = Array(n).fill(0);
    const compare = (a: Entry, b: Entry): number => a[0] - b[0] || a[1] - b[1];
    const left = new AvlTree<Entry>(compare);
    const right = new AvlTree<Entry>(compare);
    let sumL = 0,
        sumR = 0;

    for (let i = 0; i < n; ++i) {
        let item: Entry = [nums[i], i];
        if (left.count() === 0 || item[0] <= left.max()!.getValue()[0]) {
            left.insert(item);
            sumL += item[0];
        } else {
            right.insert(item);
            sumR += item[0];
        }
        if (i >= x) {
            const old: Entry = [nums[i - x], i - x];
            if (left.remove(old)) {
                sumL -= old[0];
            } else {
                right.remove(old);
                sumR -= old[0];
            }
        }
        if (left.count() > right.count() + 1) {
            item = left.max()!.getValue();
            left.remove(item);
            right.insert(item);
            sumL -= item[0];
            sumR += item[0];
        } else if (left.count() < right.count()) {
            item = right.min()!.getValue();
            right.remove(item);
            left.insert(item);
            sumL += item[0];
            sumR -= item[0];
        }
        if (i >= x - 1) {
            const mid = left.max()!.getValue()[0];
            ops[i] = mid * left.count() - sumL + sumR - mid * right.count();
        }
    }
    return ops;
}

function minOperations(nums: number[], x: number, k: number): number {
    const n = nums.length;
    const ops = getCosts(nums, x);
    let pre = Array(n + 1).fill(0);
    let cur = Array(n + 1).fill(Infinity);

    for (let j = 1; j <= k; ++j) {
        cur.fill(Infinity);
        for (let i = j * x; i <= n; ++i) {
            cur[i] = Math.min(cur[i - 1], pre[i - x] + ops[i - 1]);
        }
        [pre, cur] = [cur, pre];
    }
    return pre[n];
}