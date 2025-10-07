class Solution {
    public int minOperations(int[] nums, int k) {
    int sum=0;
    for(int i=0;i<nums.length;i++){
        sum+=nums[i];
    }
    if(sum%k==0){
        return 0;
    }
 int c=0;
 int ans=0;
    for(int i=sum;i>=0;i--){
    
        if(i%k==0){
          ans=c;
          break;
        }
        else{
            c++;
        }
    }
    return ans;
    }
}