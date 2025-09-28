class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) 
    {
        int sum=0;
        int digit=x;
        while(digit>0)
        {
           int a=digit%10;
           sum+=a;
           digit/=10; 
        }
        if(x%sum==0)
        {
           return sum;
        }
        return -1;
    }
}