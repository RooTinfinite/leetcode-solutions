class Solution {
    public int largestCombination(int[] candidates) {
       int[] ans=new int[32];
       for(int x:candidates){
           find(x,ans);
       } 
        int res=0;
       for(int i=0;i<32;i++){
           res=Math.max(res,ans[i]);//traverse the bit array and check the max value
       }
       return res;
    }
    public void find(int n,int[] ans){

        int j=31;//index for updating the values in bit array
        while(n>0){
            int a=(n&1);//for checking if bit is set or not
            ans[j]+=a;
            n>>=1;//left shift the given no
            j--;
        }
    }
}