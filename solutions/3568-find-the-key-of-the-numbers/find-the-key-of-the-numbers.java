class Solution {
    public int generateKey(int num1, int num2, int num3) {
        int ans=0 ,count=1,i=0;
        while(i<4){
        int min=Math.min(num1 % 10 ,Math.min(num2 % 10,num3 % 10));
        ans=ans + min*count;
        num1/=10;
        num2/=10;
        num3/=10;
        count*=10;
        i++;
       }
       return ans;
    }
}