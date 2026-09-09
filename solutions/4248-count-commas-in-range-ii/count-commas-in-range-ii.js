var countCommas = function (n) {
    let p = 1000, res = 0;
    while (p <= n) {
        res += n - p + 1;
        p *= 1000;
    }
    return res;
};