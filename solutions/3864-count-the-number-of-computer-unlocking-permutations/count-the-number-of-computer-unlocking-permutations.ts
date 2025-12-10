function countPermutations(complexity: number[]): number {
    const n = complexity.length;
    for (let i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    let ans = 1;
    const mod = 1000000007;
    for (let i = 2; i < n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}