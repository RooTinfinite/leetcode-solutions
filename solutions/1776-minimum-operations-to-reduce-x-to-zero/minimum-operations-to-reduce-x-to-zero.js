const minOperations = (A, x) => {
    const k = A.reduce((a, c) => a + c, 0) - x;
    if (k < 0) return -1;

    let best = -1, i = 0, s = 0, n = A.length;
    for (let j = 0; j < n; j++) {
        s += A[j];
        while (s > k)
            s -= A[i++];

        if (s === k)
            best = Math.max(best, j - i + 1);
    }

    return best + 1 ? n - best : -1;
};