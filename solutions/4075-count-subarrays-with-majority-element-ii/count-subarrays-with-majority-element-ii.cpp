using ll = long long;
class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int target) {
    /*
        make all target ele. +1 and other -1
        So problem changes to count of subarray with +ve sum.
    */
        for(auto &x:nums){
            if(x==target) x=1;
            else x=-1;
        }
        return countSubArray(nums);
    }

private:
    ll countSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<ll> a(n+1);
        a[0]=0;
        for(int i=0;i<n;i++) a[i+1]=a[i]+nums[i];
        return mergeSort(a,0,n);
    }
    ll mergeSort(vector<ll>& a,int low,int high){
        ll cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergeSort(a,low,mid);
        cnt+=mergeSort(a,mid+1,high);
        cnt+=countPairs(a,low,mid,high);
        merge(a,low,mid,high);
        return cnt;
    }
    ll countPairs(vector<ll>& a,int low,int mid,int high){
        ll cnt=0;
        int right=mid+1;
        for(int left=low; left<=mid; left++){
            while(right<=high && a[right] <= a[left]) right++;
            cnt += (high - right + 1);
        }
        return cnt;
    }
    void merge(vector<ll>& a,int low,int mid,int high){
        int left=low, right=mid+1, idx=0;
        vector<ll> temp(high-low+1);
        while(left<=mid && right<=high){
            if(a[left] <= a[right]) temp[idx++]=a[left++];
            else temp[idx++]=a[right++];
        }
        while(left<=mid) temp[idx++]=a[left++];
        while(right<=high) temp[idx++]=a[right++];
        for(int p=low;p<=high;p++) a[p]=temp[p-low];
    }
    
};