class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int n:nums){
            int last=0;
            for(int d=2; d*d<=n;d++){
                if(n%d==0){
                    if(last==0){
                        last=d;
                    }else{
                        last=0;
                        break;
                    }
                }
            }
            if(last > 0 && last != n/last)
            sum+= 1 + n + last + n/last;
        }
        return sum;
    }
};