class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int ans = Integer.MAX_VALUE, s = 0, left = 0;
        int[] cnt = new int[32];
        
        for (int right = 0; right < nums.length; right++) {
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
                ans = Math.min(right - left + 1, ans);
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
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}