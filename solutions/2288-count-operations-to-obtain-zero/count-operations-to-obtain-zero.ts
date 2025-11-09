function countOperations(num1: number, num2: number): number {
    let res = 0; // total number of subtraction operations
    while (num1 && num2) {
        // each step of the Euclidean algorithm
        res += Math.floor(num1 / num2);
        num1 %= num2;
        // swap two numbers
        [num1, num2] = [num2, num1];
    }
    return res;
}