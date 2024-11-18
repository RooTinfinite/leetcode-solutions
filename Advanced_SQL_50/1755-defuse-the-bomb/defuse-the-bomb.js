// JavaScript

var decrypt = function(code, k) {
    const N = code.length;
    const res = new Array(N).fill(0);
    
    for (let i = 0; i < N; i++) {
        if (k > 0) {
            for (let j = i + 1; j < i + 1 + k; j++) {
                res[i] += code[j % N];
            }
        } else if (k < 0) {
            for (let j = i - 1; j > i - 1 + k; j--) {
                res[i] += code[((j % N) + N) % N];
            }
        }
    }
    
    return res;
};