const isPowerOfTwo = n => n > 0 && !(n & (n - 1))
const consecutiveSetBits = n => isPowerOfTwo(n & (n >> 1))