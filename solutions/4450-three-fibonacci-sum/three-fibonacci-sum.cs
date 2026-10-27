public class Solution {
    public bool ThreeFibonacciSum(int n, int a = 0, int b = 1, int c = 1) => a + b + c < n
        ? ThreeFibonacciSum(n, b, c, b + c)
        : a + b + c == n;

}