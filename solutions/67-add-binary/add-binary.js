// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
var addBinary = function (a, b) {
    let x = BigInt(`0b${a}`);
    let y = BigInt(`0b${b}`);
    let zero = BigInt(0);
    while (y != zero) {
        let answer = x ^ y;
        let carry = (x & y) << BigInt(1);
        x = answer;
        y = carry;
    }
    return x.toString(2);
};