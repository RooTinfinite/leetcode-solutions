class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
          int n=units.size();
        if(n==1)return *min_element(units[0].begin(),units[0].end());
        long long sum=0;
        bool flag=true;
        for(auto&it:units){
            if(it.size()==1)sum+=it[0];
            else{
                flag=false;
                break;
            }
        }
        if(flag)return sum;
        sum=0;
        int minm=INT_MAX,sminm=INT_MAX;
        for(auto& it:units){
            int mn1=INT_MAX,mn2=INT_MAX;
            for(int x:it){
                if(x<mn1){
                    mn2=mn1;
                    mn1=x;
                }
                else if(x<mn2){
                    mn2=x;
                }
            }
            sum+=mn2;
            minm=min(minm,mn1);
            sminm=min(sminm,mn2);
        }
        return minm+sum-sminm;
    }
};