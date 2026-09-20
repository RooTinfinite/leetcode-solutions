var reverseDegree = function (s) {
    let ans = 0;
    for (let i = 1; i <= s.length; i++) {
        ans += (26 - (s.charCodeAt(i - 1) - 'a'.charCodeAt(0))) * i;
    }
    return ans;
};