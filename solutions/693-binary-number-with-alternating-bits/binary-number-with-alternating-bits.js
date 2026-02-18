var hasAlternatingBits = function(n) {
    let x = n ^ (n >> 1);
    return (x & (x + 1)) === 0;
};