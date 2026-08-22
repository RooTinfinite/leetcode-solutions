var checkDivisibility = function (n) {
    let digitSum = 0;
    let digitProduct = 1;
    let original = n;

    while (n > 0) {
        let digit = n % 10;
        n = Math.floor(n / 10);

        digitSum += digit;
        digitProduct *= digit;
    }

    return original % (digitSum + digitProduct) === 0;
};