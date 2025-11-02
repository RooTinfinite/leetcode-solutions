var countNumbersWithUniqueDigits = function(n) {
    if (n === 0) return 1;
    if (n === 1) return 10;

    let result = 10;
    let current = 9;

    for (let i = 2; i <= n; i++) {
        current *= (10 - (i - 1));
        result += current;
    }

    return result;
};