class Solution {

    public int sumBase(int n, int k) {
        int sum = 0;
        
        while (n > 0) {
            int quotient = n / k;
            int remainder = n % k;
            n = quotient;
            sum += remainder;
        }
        
        return sum;
    }
}