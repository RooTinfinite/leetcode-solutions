class Solution {
public:
    bool check(long long sum,int x){
        int a=sum%10;
        if(a!=x)return false;
        int b=0;
        while(sum>0){
            b=sum%10;
            sum/=10;
        }
        return b==x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        vector<long long>pfx(n,0);
        pfx[0]=nums[0];
        for(int i=1;i<n;i++)pfx[i]=pfx[i-1]+nums[i];
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long sum = pfx[j];
                if(i>0)sum-=pfx[i-1];
                if(check(sum,x))ans++;
            }
        }
        return ans;
    }
};