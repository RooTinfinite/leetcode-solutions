class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int ans = INT_MAX;
        int s = 0;
        int left = 0;
        std::vector<int> cnt(32, 0);
        
        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];
            s |= num;
            int i = 0;
            
            while (num > 0) {
                cnt[i] += num % 2;
                num /= 2;
                ++i;
            }

            while (s >= k && left <= right) {
                ans = std::min(right - left + 1, ans);
                num = nums[left];
                i = 0;

                while (num > 0) {
                    if (num % 2) {
                        cnt[i] -= 1;
                        if (cnt[i] == 0) {
                            s ^= (1 << i);
                        }
                    }
                    num /= 2;
                    ++i;
                }
                ++left;
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};