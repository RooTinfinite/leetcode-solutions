using int3 = array<int, 3>; // (y, a, b) where x = y * 2^a * 5^b and gcd(y,10) = 1

int3 C[100000];

class Solution {
public:
    int3 factor(int x) {
        int a = countr_zero((unsigned)x);
        x >>= a;
        int b = 0;
        while (x % 5 == 0) {
            x /= 5;
            b++;
        }
        return {x % 10, a, b}; // Only keep mod 10 for y
    }

    int3 inverse(const int3& x) {
        int x0 = x[0], a = x[1], b = x[2];
        // Modular inverse under mod 10 using Euler's theorem (Euler-phi(10)=4)
        int x0_inv = (x0*x0*x0) % 10; // x0^3 is inverse mod 10
        return {x0_inv, -a, -b};
    }

    int3 mult(const int3& x, const int3& y) {
        return {x[0]*y[0]%10, x[1]+y[1], x[2]+y[2]};
    }

    int toInt(const int3& x) { // mod 10
        if (x[1] >= 1 && x[2] >= 1) return 0;
        if (x[2] >= 1) return 5;
        int B[4] = {6, 2, 4, 8}; // 2^x(mod 10) cycle
        if (x[1] == 0) return x[0];
        int B2 = B[x[1] % 4]; // 
        return x[0] * B2 % 10;
    }

    void compute_comb(int N) {
        C[0] = {1, 0, 0}; 
        if (N == 0) return; // Prevent C[N] access if N=0
        C[N] = {1, 0, 0}; 

        for (int k = 1; k <= N/2; k++) {
            int3 P = factor(N-k + 1);
            int3 Q = inverse(factor(k));
            C[k]=C[N-k] = mult(mult(C[k-1], P), Q);
        }
    }

    bool hasSameDigits(string& s) {
        int n = s.size();

        fill(C, C+(n-2), int3{0, 0, 0}); // Prevent overflow
        compute_comb(n-2);

        int sum=0;
        for (int i=0; i <= n-2; i++) {
            int C_val= (toInt(C[i])*(s[i]-s[i+1]))%10;
            sum=(sum+C_val+10) % 10; // Ensure non-negative
        }

     //   cout << sum << endl;
        return sum == 0;
    }
};