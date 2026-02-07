/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function(s) {
    let bCount = 0;
    let res = 0;
    const n = s.length;
    
    for (let i = 0; i < n; i++) {
        if (s.charCodeAt(i) === 98) { 
            bCount++;
        } else {
            if (res + 1 < bCount) {
                res++;
            } else {
                res = bCount;
            }
        }
    }
    
    return res;
};