// TypeScript
function climbStairs(n: number): number {
    let sqrt5 = Math.sqrt(5);
    let phi = (1 + sqrt5) / 2;
    let psi = (1 - sqrt5) / 2;
    return Math.floor((Math.pow(phi, n + 1) - Math.pow(psi, n + 1)) / sqrt5);
}