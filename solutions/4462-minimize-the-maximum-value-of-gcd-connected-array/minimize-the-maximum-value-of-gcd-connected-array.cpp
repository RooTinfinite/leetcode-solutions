class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1) return -1;

        int minDivisor = value;

        for(int i = 2 ; i*i<=value ; i++)
        {
            if(value%i==0)
            {
                minDivisor=i;
                break;
            }
        }
    
        if(value - minDivisor < 2LL * index) return -1;

        int right = n-index-1;

        if(right==0) return value;

        return 1LL * value + minDivisor + 2LL * (right - 1);
    }
};