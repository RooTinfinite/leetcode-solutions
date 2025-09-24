class Solution {
public:
    int helper(int num) {
        int mx = 0;
        while (num > 0) {
            mx = max(mx, num % 10);
            num /= 10;
        }
        return mx;
    }

    int maxSum(vector<int>& nums) {
        int n= nums.size();
       int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a= nums[i],b =nums[j];
                if(helper(a)==helper(b)){
                    ans = max(a+b,ans);
                }
            }
        }
        return ans;
    }
};