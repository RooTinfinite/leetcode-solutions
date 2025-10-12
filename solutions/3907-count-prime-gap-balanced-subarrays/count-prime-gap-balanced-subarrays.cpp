class Solution {
public:
    int p=50001;
    vector<bool>isprime;
    
    void sieve(){
        isprime.resize(p,true);
        int n=isprime.size();
        isprime[0]=isprime[1]=false;
        for(long long i=2;i<n;i++){
            if(isprime[i]){
                for(long long j=i*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        sieve();
        int n=nums.size();
        multiset<int>st;
        int l=0,r=0;
        int ans=0;
        int fl=-1,sl=-1; //fl=first last prime , sl=second last prime
        for(int r=0;r<n;r++){
            if(isprime[nums[r]]){
                st.insert(nums[r]);
                sl=fl;
                fl=r;
            }

            //shrinking window upto when diff between max & min >k    
            while(st.size()>1 && *st.rbegin()-*st.begin()>k){
                if(isprime[nums[l]]){
                    st.erase(st.find(nums[l]));
                }
                l++;
            }
           
            if(st.size()>=2){
                ans+=(sl-l+1); // adding all subarray second last(sl) to l(sl--->l---->r)
            }
        }
        return ans;
    }
};