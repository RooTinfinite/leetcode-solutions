function kthCharacter(k: number, operations: number[]): string {
    let ans = 0;
    k--;
    for (let i = Math.floor(Math.log2(k)); i >= 0; i--) {
        if ((BigInt(k) >> BigInt(i)) & 1n) {
            ans += operations[i];
        }
    }
    return String.fromCharCode("a".charCodeAt(0) + (ans % 26));
}