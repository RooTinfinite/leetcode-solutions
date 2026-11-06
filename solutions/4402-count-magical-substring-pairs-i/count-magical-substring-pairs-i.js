
/**
 * @param {string} s
 * @return {number}
 */
var countMagicalPairs = function(s) {
    let n = s.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        let seen1 = new Array(27).fill(false);
        let l = new Array(27).fill(0);
        let r = new Array(27).fill(0);
        let ans1 = 0;

        for (let j = i; j >= 0; j--) {
            let c = s.charCodeAt(j) - 97;

            if (!seen1[c]) {
                seen1[c] = true;
                ans1++;
            }

            l[ans1]++;
        }

        let seen2 = new Array(27).fill(false);
        let ans2 = 0;

        for (let k = i + 1; k < n; k++) {
            let c = s.charCodeAt(k) - 97;

            if (!seen2[c]) {
                seen2[c] = true;
                ans2++;
            }

            r[ans2]++;
        }

        for (let x = 1; x <= 26; x++) {
            res += l[x] * r[x];
        }
    }

    return res;
};