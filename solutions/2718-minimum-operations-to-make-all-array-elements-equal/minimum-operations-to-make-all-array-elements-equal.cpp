class Solution {
public:
    long long upperBound(vector<int>& arr,int& val){
        long long left=0;
        long long right=arr.size();
        while(left<right){
            long long mid=(left+right)/2;
            if(arr[mid]<=val){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> ans;
        vector<long long> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        for(auto q:queries){
            long long qVal=q;
            long long idx=upperBound(nums,q);
            long long dec=0;
            long long inc=0;
            inc=abs((idx)*qVal-pref[idx]);
            dec=(pref[n]-pref[idx])-((n-idx)*qVal);
            ans.push_back(inc+dec);
        }
        return ans;
    }
};