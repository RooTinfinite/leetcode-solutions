class Solution {
public:
    int gcd(int a,int b)
    {
        if(a == 0)
        {
            return b;
        }
        return gcd(b%a,a);
    }
    int findGCD(vector<int>& nums) {
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            a=min(a,nums[i]);
            b=max(b,nums[i]);
        }
        return gcd(a,b);
    }
};