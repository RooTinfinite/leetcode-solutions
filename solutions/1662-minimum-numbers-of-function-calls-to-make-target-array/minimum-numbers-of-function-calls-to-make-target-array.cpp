class Solution {
public:
    int minOperations(vector<int>& nums) {
        int add=0, mul=0;

        for (auto it : nums) {
            int curMul = 0;
            while (it > 0) {
                if (it % 2 == 1) add++;
                it /= 2;
                if (it > 0) curMul++;
            }
            mul = max(mul, curMul);
        }

        return add + mul;
    }
};