function reverse(n: number): number {
    let res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    return res;
}

function mirrorDistance(n: number): number {
    return Math.abs(n - reverse(n));
}