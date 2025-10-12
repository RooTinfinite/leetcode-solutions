class Solution {
    public int countPartitions(int[] nums, int k) {
        int n=nums.length;
        int MOD= 1000000007;
        int[] dp=new int[nums.length+1];
        int[] prefix=new int[nums.length+2];
        dp[0]=1;
        prefix[1]=1;
        Deque<Integer> max=new ArrayDeque<>();
        Deque<Integer> min=new ArrayDeque<>();
        int l=0;
        for(int r=0;r<n;r++){
            while(!max.isEmpty() && nums[max.peekLast()]<nums[r]){
                max.pollLast();
            }
            max.offerLast(r);
            while(!min.isEmpty() && nums[min.peekLast()]>nums[r]){
                min.pollLast();
            }
            min.offerLast(r);
            while(!max.isEmpty() && !min.isEmpty() && nums[max.peekFirst()]-nums[min.peekFirst()]>k){
                if(max.peekFirst()==l) max.pollFirst();
                if(min.peekFirst()==l) min.pollFirst();
                l++;
            }
            dp[r+1]=(prefix[r+1]-prefix[l]+MOD)%MOD;
            prefix[r+2]=(prefix[r+1]+dp[r+1])%MOD;
        }
        return dp[n];
    }
}