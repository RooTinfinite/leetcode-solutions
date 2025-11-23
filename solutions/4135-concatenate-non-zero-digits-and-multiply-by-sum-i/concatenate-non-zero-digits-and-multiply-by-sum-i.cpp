class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0, i = 1;
        while(n > 0) {
            int m = n % 10;
            n /= 10;
            if(m == 0) continue;
            sum += m;
            x += (m * i);
            i *= 10;
        }
        return (long long) x * sum;
    }
};