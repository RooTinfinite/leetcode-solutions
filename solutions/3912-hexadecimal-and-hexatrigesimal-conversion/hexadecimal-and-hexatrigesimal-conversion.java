public class Solution {
    public String concatHex36(int n) {
        long n2 = (long) n * n;
        long n3 = (long) n * n * n;

        // Convert to hexadecimal (uppercase)
        String hexPart = Long.toHexString(n2).toUpperCase();

        // Convert to base-36 (uppercase)
        String base36Part = "";
        while (n3 > 0) {
            long rem = n3 % 36;
            char ch;
            if (rem < 10) ch = (char) ('0' + rem);
            else ch = (char) ('A' + rem - 10);
            base36Part = ch + base36Part;
            n3 /= 36;
        }

        return hexPart + base36Part;
    }
}
