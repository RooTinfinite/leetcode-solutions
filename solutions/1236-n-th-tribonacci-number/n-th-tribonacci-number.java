class Solution {
    public int tribonacci(int n) {
        // Initialize the first three numbers of the sequence
        int a = 0, b = 1, c = 1, d=0;
        
        // Check if n is 0
        if (n == 0)
            return a;
        
        // Check if n is 1 or 2
        if (n == 1 || n == 2)
            return 1;
        
        // Calculate each subsequent number in the sequence starting from the 3rd number
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        
        // Return the n-th number in the sequence
        return d;
    }
}