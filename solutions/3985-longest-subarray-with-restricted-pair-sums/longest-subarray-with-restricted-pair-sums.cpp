class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, l = 0;
        int hash[501] = {0};

        auto valid = [&](int r) {
            for(int i = 1; i <= r / 2; ++i) {
                if(i == r - i) {
                    if(hash[i] >= 2) return false;
                } else {
                    if(hash[i] && hash[r - i]) return false;
                }
            }
            for(int i = 1; i + r <= 500; ++i) {
                if(hash[i] && hash[i + r]) return false;
            }
            return true;
        };

        for(int r = 0; r < n; ++r) {
            while(!valid(nums[r])) hash[nums[l++]]--;
            hash[nums[r]]++;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};