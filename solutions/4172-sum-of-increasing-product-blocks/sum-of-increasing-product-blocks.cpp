class Solution {
public:
    int sumOfBlocks(int n) {
        long long ans = 0, i = 1, cur = 1, m = 1e9 + 7;
        for (; n; --n){
            long long next = 1;
            // loop on cur till i 
            for (int y = 0; y < i; ++y){
                next *= cur;
                next %= m;
                ++cur;
            }
            ans += next;
            ans %= m;
            ++i;
            // increment i
        }
        return ans;
    }
};