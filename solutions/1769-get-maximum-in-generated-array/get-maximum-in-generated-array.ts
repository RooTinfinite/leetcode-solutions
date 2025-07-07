function getMaximumGenerated(n: number): number {
    const inputSize = 32

    const fib = [0, 1]
    for (let i = 0; i < inputSize; i++) fib.push(fib.at(-2)! + fib.at(-1)!)

    let ans = 0
    let [zero, one] = [1, 0]

    for (let shift = inputSize - 1; shift >= 0; shift--) {
        const mask = 1 << shift
        if ((mask & n) === 0) zero += one
        else {
            ans = Math.max(ans, zero * fib[shift + 1] + one * fib[shift + 2])
            one += zero
        }
    }

    return ans
}