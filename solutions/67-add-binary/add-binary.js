var addBinary = function (a, b) {
    // Convert binary strings to BigInt
    let numA = BigInt("0b" + a);
    let numB = BigInt("0b" + b);

    // Sum the BigInt numbers
    let sum = numA + numB;

    // Convert the sum back to a binary string
    return sum.toString(2);
};