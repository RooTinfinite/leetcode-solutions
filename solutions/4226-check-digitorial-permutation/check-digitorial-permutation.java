class Solution {
    static int[] digit_frequencies(int x) {
        int[] c = new int[10];
        do {
            c[x % 10]++;
            x /= 10;
        } while (x != 0);
        return c;
    }

    public boolean isDigitorialPermutation(int n) {
        int[] factorials = new int[10];
        factorials[0] = 1;
        for (int d = 1; d < 10; ++d)
            factorials[d] = factorials[d - 1] * d;

        int digits_sum = 0, x = n;
        do {
            digits_sum += factorials[x % 10];
            x /= 10;
        } while (x != 0);

        return Arrays.equals(digit_frequencies(digits_sum), digit_frequencies(n));
    }
}