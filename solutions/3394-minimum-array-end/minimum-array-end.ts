// TypeScript

function minEnd(n: number, x: number): number {
    let result: bigint = BigInt(x);
    let remaining: bigint = BigInt(n - 1);
    let position: bigint = 1n;
    
    while (remaining > 0n) {
        if ((BigInt(x) & position) === 0n) {
            result |= (remaining & 1n) * position;
            remaining >>= 1n;
        }
        position <<= 1n;
    }
    
    return Number(result);
}