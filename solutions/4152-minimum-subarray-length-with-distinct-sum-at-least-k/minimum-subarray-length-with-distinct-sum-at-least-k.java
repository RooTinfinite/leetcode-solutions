class Solution {
    public int minLength(int[] nums, int k) {
        int[] freq = new int[100001]; 
        long distinctsum = 0; 

        int left = 0;
        int ans = Integer.MAX_VALUE;

        for (int right = 0; right < nums.length; right++) {
            int val = nums[right];

            if (freq[val] == 0) {
                distinctsum += val; 
            }
            freq[val]++;

            while (distinctsum >= k) { 
                ans = Math.min(ans, right - left + 1);

                int leftval = nums[left]; 
                freq[leftval]--; 

                if (freq[leftval] == 0) { 
                    distinctsum -= leftval; 
                }
                left++;
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}