import (
    "math/big"
)

func addBinary(a string, b string) string {
    // Convert binary strings to big.Int
    numA := new(big.Int)
    numA, ok := numA.SetString(a, 2)
    if !ok {
        return "0"
    }

    numB := new(big.Int)
    numB, ok = numB.SetString(b, 2)
    if !ok {
        return "0"
    }

    // Sum the big.Int numbers
    sum := new(big.Int).Add(numA, numB)

    // Convert the sum back to a binary string
    return sum.Text(2)
}