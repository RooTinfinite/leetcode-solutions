class FindSumPairs {
    private nums1: number[];
    private nums2: number[];
    private cnt: Map<number, number>;

    constructor(nums1: number[], nums2: number[]) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Map();
        for (const num of nums2) {
            this.cnt.set(num, (this.cnt.get(num) || 0) + 1);
        }
    }

    add(index: number, val: number): void {
        const oldVal = this.nums2[index];
        this.cnt.set(oldVal, (this.cnt.get(oldVal) || 0) - 1);
        this.nums2[index] += val;
        const newVal = this.nums2[index];
        this.cnt.set(newVal, (this.cnt.get(newVal) || 0) + 1);
    }

    count(tot: number): number {
        let ans = 0;
        for (const num of this.nums1) {
            const rest = tot - num;
            ans += this.cnt.get(rest) || 0;
        }
        return ans;
    }
}