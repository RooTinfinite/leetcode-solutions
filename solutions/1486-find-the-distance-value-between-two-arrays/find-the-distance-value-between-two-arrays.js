var findTheDistanceValue = function (arr1, arr2, d) {
    let cnt = 0;
    for (const x of arr1) {
        let ok = true;
        for (const y of arr2) {
            ok &= Math.abs(x - y) > d;
        }
        cnt += ok ? 1 : 0;
    }
    return cnt;
};