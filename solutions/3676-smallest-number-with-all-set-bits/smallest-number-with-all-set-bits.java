class Solution
{
    public int smallestNumber(int n)
    {
        String s=Integer.toBinaryString(n);
       
        for(int i=0;i<=31;i++)
        {
             int a=(1<<i)-1;
            if(a>=n)
            {
                 return a;
            }
        }
        return -1;
    }
}