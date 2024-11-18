// JavaScript

var decrypt = function(code, k) {
    const N = code.length;
    const res = new Array(N).fill(0);
    
    if (k === 0) return res;
    
    let l = 0;
    let curSum = 0;
    
    for (let r = 0; r < N + Math.abs(k); r++) {
        curSum += code[r % N];
        
        if (r - l + 1 > Math.abs(k)) {
            curSum -= code[l % N];
            l = (l + 1) % N;
        }
        
        if (r - l + 1 === Math.abs(k)) {
            if (k > 0) {
                res[(l - 1 + N) % N] = curSum;
            } else {
                res[(r + 1) % N] = curSum;
            }
        }
    }
    
    return res;
};