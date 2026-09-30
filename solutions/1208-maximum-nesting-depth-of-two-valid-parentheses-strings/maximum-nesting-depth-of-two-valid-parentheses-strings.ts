function maxDepthAfterSplit(seq: string): number[] {
    const ans: number[] = [];
    let d: number = 0;
    for (const c of seq) {
        if (c === "(") {
            d++;
            ans.push(d % 2);
        }
        if (c === ")") {
            ans.push(d % 2);
            d--;
        }
    }
    return ans;
}