// TypeScript

function decrypt(code: number[], k: number): number[] {
    const N: number = code.length;
    const res: number[] = new Array(N).fill(0);
    
    for (let i = 0; i < N; i++) {
        if (k > 0) {
            for (let j = i + 1; j < i + 1 + k; j++) {
                res[i] += code[j % N];
            }
        } else if (k < 0) {
            for (let j = i - 1; j > i - 1 - Math.abs(k); j--) {
                res[i] += code[((j % N) + N) % N];
            }
        }
    }
    
    return res;
}