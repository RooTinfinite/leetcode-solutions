/**
 * @param {string} s
 * @return {number}
 */
var countValidPrefixes = function(s) {
    let balance = 0;
    let ans = 0;

    for(const ch of s){
        balance = (ch === '1') ? balance + 1 : balance - 1;

        if(balance >= -1 && balance <= 1)
            ans++;
    }

    return ans;
};