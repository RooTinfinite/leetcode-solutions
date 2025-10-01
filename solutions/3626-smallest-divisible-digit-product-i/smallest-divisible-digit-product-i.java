public class Solution {
    public int smallestNumber(int n, int t) {
        for (int i = n; i < n + 10; i++) {
            if (productOfDigits(i) % t == 0) {
                return i; }
        }
        return -1;
    }
    
    private int productOfDigits(int x) {
        int product = 1;
        while (x > 0) {
            product *= (x % 10);
            x /= 10;}

        return product;
    }
}