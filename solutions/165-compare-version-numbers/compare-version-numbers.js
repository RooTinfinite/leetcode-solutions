var compareVersion = function (version1, version2) {
    var getNextChunk = function (version, n, p) {
        if (p > n - 1) {
            return [0, p];
        }
        let pEnd = p;
        while (pEnd < n && version[pEnd] != ".") {
            pEnd++;
        }
        let i = parseInt(version.substring(p, pEnd != n - 1 ? pEnd : n));
        p = pEnd + 1;
        return [i, p];
    };

    let p1 = 0,
        p2 = 0;
    let n1 = version1.length,
        n2 = version2.length;
    while (p1 < n1 || p2 < n2) {
        let [i1, p1_] = getNextChunk(version1, n1, p1);
        p1 = p1_;
        let [i2, p2_] = getNextChunk(version2, n2, p2);
        p2 = p2_;
        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }
    return 0;
};