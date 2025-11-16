var grayCode = function (n) {
    let result = [];
    // there are 2 ^ n numbers in the Gray code sequence.
    let sequenceLength = 1 << n;
    for (let i = 0; i < sequenceLength; i++) {
        let num = i ^ (i >> 1);
        result.push(num);
    }
    return result;
};