class Solution {
    static std::array<int, 10> digit_frequencies(int x) {
        std::array<int, 10> c{}; 
        do { 
            c[x % 10]++; 
            x /= 10; 
        } while (x);
        return c;
    }

public:
    bool isDigitorialPermutation(int n) {
        int factorials[10]; 
        factorials[0] = 1;
        for (int d = 1; d < 10; ++d) 
            factorials[d] = factorials[d - 1] * d;

        int digits_sum = 0, x = n;
        do { 
            digits_sum += factorials[x % 10]; 
            x /= 10; 
        } while (x);

        return digit_frequencies(digits_sum) == digit_frequencies(n);
    }
};