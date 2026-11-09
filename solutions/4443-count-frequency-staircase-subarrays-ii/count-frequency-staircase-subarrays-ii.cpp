class Solution {
public:
    int countStaircase(vector<int>& num) {
        unordered_map<int,int> id;
        unordered_map<int,int> val;
        int n=num.size();
        int mx,j,curr;
        curr=0;        
        vector<vector<int>> mp(n+1);
        for(int i=0; i<n; i++) {
            if(id.find(num[i])==id.end()) {
                id[num[i]]=curr++;
            }
            num[i]=id[num[i]];
            val[i]=mp[num[i]].size();
            mp[num[i]].push_back(i);
        }        
        for(int i=0; i<curr; i++) mp[i].push_back(n);
        int ans=0;        
        vector<int> vis(n+1,-1);
        for(int i=0; i<n; i++) {
            mx=n;
            j=i;
            curr=0;
            while(j<n && j<mx) {
                if(vis[num[j]]!=i) {
                    curr++;
                    if(i+((curr)*(curr+1))/2>n) break;                    
                    int pos=val[j]+curr;                   
                    if(pos>=mp[num[j]].size()) break;
                    mx=min(mx,mp[num[j]][pos]);
                    vis[num[j]]=i;
                }
                if((j-i+1)==((curr)*(curr+1))/2) ans++;
                j++;
            }
        }
        return ans;
    }
};