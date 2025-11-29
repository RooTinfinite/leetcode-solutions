double binaryExp(double x, long n) {
    if (n == 0) return 1.0;
    // Handle case where, n < 0
    if (n < 0) {
        n = -n;
        x = 1.0 / x;
    }
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
            n--;
        }
        // We square x and reduce n by half, x^n => (x^2)^(n/2)
        x = x * x;
        n = n / 2;
    }
    return result;
}
double myPow(double x, int n) { return binaryExp(x, (long)n); }