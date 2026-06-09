var mapWordWeights = function (words, weights) {
    let ans = "";
    for (const word of words) {
        let s = 0;
        for (const c of word) {
            s += weights[c.charCodeAt(0) - "a".charCodeAt(0)];
        }
        ans += String.fromCharCode("z".charCodeAt(0) - (s % 26));
    }
    return ans;
};