class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 == 0) {
            long long x = num / 3;

            long long second = x, first = x - 1, third = x + 1;

            return {first, second, third};
        }

        return {};
    }
};