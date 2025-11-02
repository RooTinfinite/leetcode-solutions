class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
        {
            return 1;
        }
        long long res=10;
        for(int i=2;i<=n;i++)
        {
            long long c=9;
            long long j=i-1;
            long long r=9;
            while(j > 0)
            {
                r=r*c;
                c--;
                j--;
            }
            res+=r;
        }
        
        return res;
        
    }
};