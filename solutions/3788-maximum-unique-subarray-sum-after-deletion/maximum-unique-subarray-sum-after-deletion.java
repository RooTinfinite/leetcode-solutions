class Solution {
    public int maxSum(int[] nums) {
        int max = Integer.MIN_VALUE;
        HashSet<Integer> set = new HashSet<>();
        for(int num:nums){
            if(num>0){
                 set.add(num);
            }   
            max = Math.max(max,num);
        }

        if(max<0){
            return max;
        }
        int ans =0;
        for(int num:set){
            ans+=num;
        }

        return ans;
    }
}