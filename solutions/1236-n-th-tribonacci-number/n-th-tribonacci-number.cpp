class Solution {
public:
    int tribonacci(int n) {
        int a=0, b=1, c=1,d;  // Initialize the first three terms of the sequence
        if(n==0)
            return a;  // If n is 0, return the first term
        if(n==1 || n==2)
            return 1;  // If n is 1 or 2, return the second or third term respectively
        for(int i=3;i<=n;i++){  // Start the loop from the third term
            d = a + b + c;  // Calculate the next term in the sequence
            a = b;  // Update the value of a
            b = c;  // Update the value of b
            c = d;  // Update the value of c
        }
        return d;  // Return the nth term
    }
};