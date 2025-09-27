class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            int temp=nums[i];
            int max=Integer.MIN_VALUE;
            while(temp!=0){
                int d=temp%10;
                temp/=10;
                if(max<d){
                    max=d;
                }
            }
            temp=nums[i];
            int rev=0;
            while(temp!=0){
                 rev=rev*10+max;
                 temp/=10;
            }
            sum+=rev;
        }
        return sum;
    }
}