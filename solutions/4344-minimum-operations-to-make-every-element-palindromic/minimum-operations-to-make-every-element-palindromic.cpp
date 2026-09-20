class Solution {
public:
    // 10 digits atmax 
    inline static bool fl=0;
    inline static vector<long long>e,o;
    void precomp(){
        if(fl)return;
        for(int i=1;i<=1e4;i++){
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(),rev.end());
            vector<string>arr= {"","0","1","2","3","4","5","6","7","8","9"};
            for(int i=0;i<11;i++){
                long long val = stoll(s+arr[i]+rev);
                if(val > 1e9)continue;
                if(val % 2 == 0)e.push_back(val);
                else o.push_back(val);
            }
        }
        fl=1;
        for(int i=1;i<10;i++){
            if(i%2)o.push_back(i);
            else e.push_back(i);
        }
        sort(e.begin(),e.end());
        sort(o.begin(),o.end());
    }
    long long minOperations(vector<int>& nums) {
        precomp();
        
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                // <= , >
                int ind = upper_bound(e.begin(),e.end(),nums[i])-e.begin();
                long long op1 =(ind < e.size() ) ? (1LL*e[ind] - nums[i])/2 : 1e9;
                long long op2 = (ind > 0 )? (1LL*nums[i]-e[ind-1])/2 : 1e9;
                ans += min(op1,op2);
                // cout<<min(op1,op2)<<endl;

            }else{
                int ind = upper_bound(o.begin(),o.end(),nums[i])-o.begin();
                long long op1 = (ind < o.size() ) ? (1LL*o[ind] - nums[i])/2 : 1e9;
                long long op2 = (ind > 0 )? (1LL*nums[i]-o[ind-1])/2 : 1e9;
                ans += min(op1,op2);
                // cout<<min(op1,op2)<<endl;

            }
        }
        return ans;
    }
};