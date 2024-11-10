public class Solution {
    public int MinimumSubarrayLength(int[] nums, int k) {
        int ans = int.MaxValue, s = 0, left = 0;
        int[] cnt = new int[32];
        
        for (int right = 0; right < nums.Length; right++) {
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
                ans = Math.Min(right - left + 1, ans);
                temp = nums[left];
                i = 0;
                while (temp > 0) {
                    if (temp % 2 == 1) {
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
        return ans == int.MaxValue ? -1 : ans;
    }
}