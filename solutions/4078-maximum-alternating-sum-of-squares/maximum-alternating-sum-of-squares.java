class Solution {
    public long maxAlternatingSum(int[] nums) {

        for(int i =0;i<nums.length;i++){
            if(nums[i] < 0) nums[i] *= -1;
        }
        Arrays.sort(nums);

        int n = nums.length;
        long sum =0;
        for(int i = n/2 ; i<n;i++) sum += nums[i]*nums[i];
        for(int i =0;i<n/2;i++) sum -= nums[i]*nums[i];

        return sum;
        
    }
}