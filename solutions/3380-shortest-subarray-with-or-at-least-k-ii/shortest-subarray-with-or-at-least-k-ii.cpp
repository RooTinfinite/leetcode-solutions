class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX, s = 0, left = 0;
        vector<int> cnt(32, 0);
        
        for (int right = 0; right < nums.size(); right++) {
            int num = nums[right];
            s |= num;
            int i = 0;
            int temp = num;
            while (temp > 0) {
                cnt[i] += temp % 2;
                temp /= 2;
                i++;
            }
            
            while (s >= k && left <= right) {
                ans = min(right - left + 1, ans);
                temp = nums[left];
                i = 0;
                while (temp > 0) {
                    if (temp % 2) {
                        cnt[i]--;
                        if (cnt[i] == 0) {
                            s ^= 1 << i;
                        }
                    }
                    temp /= 2;
                    i++;
                }
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};