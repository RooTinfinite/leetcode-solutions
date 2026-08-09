function largestInteger(n, s) {
    let res = 0;
    for (const min = Math.min; s; s -= min(s, 9)) {
        if (!n--) return -1;
        res = res * 10 + min(s, 9);
    }
    return res * 10 ** n;
}