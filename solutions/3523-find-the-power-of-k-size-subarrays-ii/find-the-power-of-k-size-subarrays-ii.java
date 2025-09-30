class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length, cnt = 1;
        if(k == 1) return nums;
        int[] res = new int[n-k+1];
        Arrays.fill(res, -1);

        for(int i=1; i<n; i++)
        {
            if(nums[i] != nums[i-1]+1)
            cnt = 1;
            else
            {
                cnt++;
                if(cnt >= k)
                res[i-k+1] = nums[i];
            }
        }
        return res;
    }
}