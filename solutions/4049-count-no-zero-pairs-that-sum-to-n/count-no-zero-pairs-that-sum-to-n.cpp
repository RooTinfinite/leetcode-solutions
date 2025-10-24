class Solution {
public:
    long long countNoZeroPairs(long long n) {
        if (n <= 1) return 0;

        vector<int> digits;
        long long tmp = n;
        while (tmp > 0) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }

        int L = digits.size();
        long long result = 0;

        for (int la = 1; la <= L; la++) {
            for (int lb = 1; lb <= L; lb++) {
                array<long long, 2> cur = {0, 0};
                cur[0] = 1;

                for (int pos = 0; pos < L; pos++) {
                    array<long long, 2> nxt = {0, 0};

                    for (int carry = 0; carry <= 1; carry++) {
                        long long ways = cur[carry];
                        if (ways == 0) continue;                      

                        int aMin;
                        int aMax;
                        if (pos < la) {
                            aMin = 1;
                            aMax = 9;
                        } else {
                            aMin = 0;
                            aMax = 0;
                        }

                        int bMin;
                        int bMax;
                        if (pos < lb) {
                            bMin = 1;
                            bMax = 9;
                        } else {
                            bMin = 0;
                            bMax = 0;
                        }

                        for (int a = aMin; a <= aMax; a++) {
                            for (int b = bMin; b <= bMax; b++) {
                                int s = a + b + carry;
                                if (s % 10 == digits[pos]) {
                                    int carryOut = s / 10;
                                    nxt[carryOut] += ways;
                                }
                            }
                        }
                    }

                    cur = nxt;
                }

                result += cur[0];
            }
        }

        return result;
    }
};