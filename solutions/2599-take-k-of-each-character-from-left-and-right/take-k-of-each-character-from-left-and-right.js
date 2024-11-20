// JavaScript

var takeCharacters = function(s, k) {
    // Total counts
    const count = [0, 0, 0];
    for (let c of s) {
        count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    
    if (Math.min(...count) < k) {
        return -1;
    }
    
    // Sliding Window
    let res = Infinity;
    let l = 0;
    for (let r = 0; r < s.length; r++) {
        count[s.charCodeAt(r) - 'a'.charCodeAt(0)]--;
        
        while (Math.min(...count) < k) {
            count[s.charCodeAt(l) - 'a'.charCodeAt(0)]++;
            l++;
        }
        res = Math.min(res, s.length - (r - l + 1));
    }
    return res;
};