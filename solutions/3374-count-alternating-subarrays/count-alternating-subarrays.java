class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long ans = 0;
        int l=0;
        int r=0;
        int n=nums.length;
        while(l<n){
            if(r<n-1 && nums[r]!=nums[r+1]){
                while(r<n-1 && nums[r]!=nums[r+1])
                    r++;
            }
            long windowSize = r-l+1;
            ans += ((windowSize*(windowSize+1))/2);
            r += 1;
            l = r;
        }     
        return ans;
    }
}