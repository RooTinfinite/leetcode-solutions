class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mp,mp2;
            int mx=0;
             for(int j=i;j<nums.size();j++){
                 int x=nums[j];
                 int oldf=mp[x];
                 if(oldf)mp2[oldf]--;
                  mp[nums[j]]++;
                 int nf=mp[x];
                 mx=max(mx,nf);
                 if(mp.size()==1){
                     ans=max(ans,j-i+1);
                     continue;
                 }
                 if(mx%2!=0)continue;
                int half=mx/2;
                 bool flag=true;
                 bool sm=false;
                     for(auto& it:mp){
                         if(it.second==0)continue;
                         if(it.second!=mx)sm=true;
                         if(it.second!=mx && it.second!=half){
                             flag=false;
                             break;
                         }
                     }
                   if(flag && sm)ans=max(ans,j-i+1);
                 }
             }
        return ans;
    }
};