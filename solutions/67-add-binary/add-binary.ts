function addBinary(a: string, b: string): string {
    // Convert binary strings to BigInt
    let numA: bigint = BigInt("0b" + a);
    let numB: bigint = BigInt("0b" + b);

    // Sum the BigInt numbers
    let sum: bigint = numA + numB;

    // Convert the sum back to a binary string
    return sum.toString(2);
}