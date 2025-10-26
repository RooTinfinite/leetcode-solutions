var removeZeros = function(n) {
    const result = n.toString().replace(/0/g, "");
    return parseInt(result, 10);
};