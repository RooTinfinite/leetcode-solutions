#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long lcm(long long x, long long y) {
        return (x / __gcd(x, y)) * y;
        //number of count of divisable by increase this makes ugly number ideal
        //very important concept 
    }

    long long count(long long x, long long a, long long b, long long c) {
        return (x / a) + (x / b) + (x / c)
               - (x / lcm(a, b)) - (x / lcm(b, c)) - (x / lcm(a, c))
               + (x / lcm(a, lcm(b, c)));
               //aubuc=a+b+c-aib-bic-aic+aibic
               //somethig 
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = 2e9, ans;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long  moto=count(mid, a, b, c);
            

            if ( moto >= n) {
                ans = mid;  // Possible answer, but try to minimize it
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};