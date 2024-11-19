var decrypt = function(code, k) {
    const n = code.length;
    const result = new Array(n).fill(0);
    
    if (k === 0) return result;
    
    let wSum = 0;
    const start = k > 0 ? 1 : n + k;
    const end = k > 0 ? k : n - 1;
    
    for (let i = start; i <= end; i++) {
        wSum += code[i % n];
    }
    
    for (let i = 0; i < n; i++) {
        result[i] = wSum;
        wSum -= code[(start + i) % n];
        wSum += code[(end + i + 1) % n];
    }
    
    return result;
};

