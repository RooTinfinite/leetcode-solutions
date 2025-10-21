class Solution {
    public int countBinaryPalindromes(long n) {
        if (n == 0) return 1;
        if (n <= 2) return 2;

        // arr[i] = total palindromes up to length i
        // pow[i] = helper array for palindrome counts by position
        int[] arr = new int[64];
        int[] pow = new int[64];  

        arr[0] = 1;
        arr[1] = 2;
        pow[0] = 1;
        pow[1] = 2;

        // precompute palindrome counts
        int half = 1;
        for (int i = 2; i < 64; i++) {
            if (i % 2 == 1) half *= 2; // odd length adds new combinations
            arr[i] = arr[i - 1] + half;
            pow[i] = pow[i - 1] * 2;
        }

        // binary representation of n (LSB → MSB)
        int[] bi = new int[64];
        long temp = n;
        for (int i = 0; i < 64; i++) {
            bi[i] = (temp & 1L) == 1 ? 1 : 0;
            temp >>= 1;
        }

        // find most significant bit (MSB)
        // we loop till 63 because long has 64 bits (1 sign bit + 63 magnitude bits)
        int msb;
        for (msb = 63; msb >= 0; msb--) {
            if (bi[msb] == 1) break;
        }

        int count = arr[msb];  // count all palindromes with smaller length

        // check bits between MSB and half
        // here i represents position (pos)
        for (int i = msb - 1; i >= (msb + 1) / 2; i--) {
            if (bi[i] == 1) {
                count += pow[(2 * i - msb) / 2];
            }
        }

        // fine adjustment: compare left & right halves
        for (int i = (msb - 1) / 2; i >= 0; i--) {
            if (bi[i] == 1 && bi[msb - i] == 0) {
                count++;
                break;
            }
            if (bi[i] != bi[msb - i]) break;
        }

        // check if n itself is a palindrome
        boolean isPal = true;
        int l = msb, r = 0;
        while (l > r) {
            if (bi[l] != bi[r]) {
                isPal = false;
                break;
            }
            l--; 
            r++;
        }
        if (isPal) count++;

        return count;
    }
}
