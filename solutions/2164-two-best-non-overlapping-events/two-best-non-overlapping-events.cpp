class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int size=e.size(),ans=0,maxi=0;
        sort(e.begin(),e.end());
        map<int,int>mp;
        while(size--){
            auto it=mp.upper_bound(e[size][1]);
            maxi=max(maxi,e[size][2]);
              mp[e[size][0]]=maxi;
            if(it==mp.end())
                ans=max(ans,maxi);
            else
                ans=max(ans,e[size][2]+it->second);
        }
        return ans;
    }
};