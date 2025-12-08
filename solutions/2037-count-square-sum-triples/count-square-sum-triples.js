var countTriples = function (n) {
    let res = 0;
    // enumerate a and b
    for (let a = 1; a <= n; a++) {
        for (let b = 1; b <= n; b++) {
            // determine if it meets the requirements
            let c = Math.floor(Math.sqrt(a * a + b * b + 1));
            if (c <= n && c * c === a * a + b * b) {
                res++;
            }
        }
    }
    return res;
};