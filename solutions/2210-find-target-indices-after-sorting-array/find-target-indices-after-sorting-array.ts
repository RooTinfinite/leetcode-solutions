function targetIndices(nums: number[], target: number): number[] {
    let cnt1: number = 0; // Number of elements less than target
    let cnt2: number = 0; // Number of elements equal to target

    for (const num of nums) {
        if (num < target) {
            cnt1++;
        } else if (num === target) {
            cnt2++;
        }
    }

    const res: number[] = [];
    for (let i = cnt1; i < cnt1 + cnt2; i++) {
        res.push(i);
    }
    return res;
}