class Solution {
    public long findMaximumScore(List<Integer> nums) {
        long ans=0; int n = nums.size();
        int prev=0;
        for(int i=1;i<n;i++){
            if(nums.get(i)>nums.get(prev)){
                ans += (long)(i-prev)*nums.get(prev);
                prev = i;
            }
        }
        return ans + (long)(n-1-prev)*nums.get(prev);
    }
}