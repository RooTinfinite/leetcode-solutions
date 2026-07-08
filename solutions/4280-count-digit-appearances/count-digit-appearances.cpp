class Solution {
public:
    int tempFunction(int n,int digit)
    {
        int cnt = 0;
        while(n>0)
        {
            int d = n%10;
            if(d==digit) cnt++;
            n/=10;
        }
        return cnt;
    }

    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ;i<n ;i++)
        {
            ans+=(tempFunction(nums[i],digit));
        }
        return ans;
    }
};