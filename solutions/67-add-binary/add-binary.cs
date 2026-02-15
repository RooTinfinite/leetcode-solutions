public class Solution {
    public string AddBinary(string a, string b) {
        // Convert binary strings to BigInteger
        BigInteger x = ConvertBinaryToBigInteger(a);
        BigInteger y = ConvertBinaryToBigInteger(b);
        BigInteger zero = BigInteger.Zero;
        BigInteger carry;

        while (y != zero) {
            carry = (x & y) << 1;
            x ^= y;
            y = carry;
        }

        // Convert the final BigInteger back to a binary string properly
        return BigIntegerToBinaryString(x);
    }

    private BigInteger ConvertBinaryToBigInteger(string binary) {
        BigInteger result = 0;
        foreach (char c in binary) {
            result = result * 2 + (c - '0');
        }

        return result;
    }

    private string BigIntegerToBinaryString(BigInteger number) {
        if (number == 0)
            return "0";  // Edge case for zero
        var binary = "";
        while (number > 0) {
            binary = ((number & 1) == 1 ? "1" : "0") + binary;
            number >>= 1;
        }

        return binary;
    }
}