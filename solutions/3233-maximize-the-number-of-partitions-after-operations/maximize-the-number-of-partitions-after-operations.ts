function maxPartitionsAfterOperations(s: string, k: number): number {
    const n: number = s.length;
    const left: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));
    const right: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));

    let num: number = 0,
        mask: number = 0,
        count: number = 0;
    for (let i = 0; i < n - 1; i++) {
        const binary: number = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        left[i + 1][0] = num;
        left[i + 1][1] = mask;
        left[i + 1][2] = count;
    }

    num = 0;
    mask = 0;
    count = 0;
    for (let i = n - 1; i > 0; i--) {
        const binary: number = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        right[i - 1][0] = num;
        right[i - 1][1] = mask;
        right[i - 1][2] = count;
    }

    let max: number = 0;
    for (let i = 0; i < n; i++) {
        let seg: number = left[i][0] + right[i][0] + 2;
        let totMask: number = left[i][1] | right[i][1];
        let totCount: number = 0;
        while (totMask) {
            totMask = totMask & (totMask - 1);
            totCount++;
        }
        if (left[i][2] === k && right[i][2] === k && totCount < 26) {
            seg++;
        } else if (Math.min(totCount + 1, 26) <= k) {
            seg--;
        }
        max = Math.max(max, seg);
    }
    return max;
}