class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        const int MAXV = 100000;

        vector<bool> exists(MAXV + 1, false);

        for(int x : nums) {
            exists[x] = true;
        }

        long long ans = 0;

        for(int x : nums) {
            int best = x;

            // find smallest array element dividing x
            for(int d = 1; 1LL * d * d <= x; d++) {
                if(x % d == 0) {
                    // divisor d
                    if(exists[d]) {
                        best = d;
                        break;
                    }

                    // paired divisor
                    int other = x / d;
                    if(exists[other]) {
                        best = min(best, other);
                    }
                }
            }

            ans += best;
        }
        return ans;
    }
};