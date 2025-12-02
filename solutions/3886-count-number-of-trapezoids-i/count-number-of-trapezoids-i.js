var countTrapezoids = function (points) {
    const pointNum = new Map();
    const mod = 1000000007n;
    let ans = 0n,
        sum = 0n;

    for (const point of points) {
        const y = point[1];
        pointNum.set(y, (pointNum.get(y) || 0) + 1);
    }

    for (const pNum of pointNum.values()) {
        const edge = (BigInt(pNum) * BigInt(pNum - 1)) / 2n;
        ans = (ans + edge * sum) % mod;
        sum = (sum + edge) % mod;
    }

    return Number(ans);
};