class Solution {
    typedef long long int ll;
//this function simply does a binary search for the no. of alloys, and 
//will return the possible max number of alloys that can be build using given machine and budget.
    int bs(int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost,int smax){

        int l=0;
        int r=smax+budget;
        int ans = 0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            
            ll cur_cost = 0;
            for(int i=0;i<composition.size();i++){
                ll faltu = (ll)(mid*composition[i]);
                if(faltu>stock[i])
                cur_cost += (ll)(((ll)(mid*composition[i])-stock[i])*cost[i]);
            }
            if(cur_cost<=budget) {ans = max((int)mid,ans); l=mid+1;}
            else r=mid-1;
        }
        return (int)ans;
    }

public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

        //simply find max no. of alloys for each machine and return maximum among then.
        int ans = 0;
        int smax = stock[max_element(stock.begin(),stock.end())-stock.begin()];
        for(int i=0;i<k;i++){
            int p = bs(n,budget,composition[i],stock,cost,smax);
            ans = max(p,ans);
        }
        
        return ans;
    }
};