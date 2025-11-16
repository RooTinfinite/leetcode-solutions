function numSub(s: string): number {
    const MODULO = 1000000007;
    let total = 0;
    let consecutive = 0;
    for (const c of s) {
        if (c === "0") {
            total += (consecutive * (consecutive + 1)) / 2;
            total %= MODULO;
            consecutive = 0;
        } else {
            consecutive++;
        }
    }
    total += (consecutive * (consecutive + 1)) / 2;
    total %= MODULO;
    return total;
}