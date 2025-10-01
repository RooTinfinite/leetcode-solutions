class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] * nums[0];

        vector<int> pregcd(n, 0), postgcd(n, 0);
        vector<long long> prelcm(n, 0), postlcm(n, 0);
        pregcd[0] = prelcm[0] = nums[0];

        --n;
        for (int i = 1; i <= n; ++i) {
            pregcd[i] = gcd(nums[i], pregcd[i - 1]);
            prelcm[i] = lcm(prelcm[i - 1], nums[i]);
        }
        
        postgcd[n] = postlcm[n] = nums[n];
        for (int i = n - 1; i >= 0; --i) { 
            postgcd[i] = gcd(nums[i], postgcd[i + 1]);
            postlcm[i] = lcm(postlcm[i + 1], nums[i]);
        }
        
        long long res = max(
            max(postlcm[0] * postgcd[0], postlcm[1] * postgcd[1]),
            prelcm[n - 1] * pregcd[n - 1]
        );
        
        long long cur;
        for (int i = 1; i < n; ++i) {
            cur = lcm(prelcm[i - 1], postlcm[i + 1]) *
                    gcd(pregcd[i - 1], postgcd[i + 1]);
            res = max(cur, res);
        }

        return res;
    }
};