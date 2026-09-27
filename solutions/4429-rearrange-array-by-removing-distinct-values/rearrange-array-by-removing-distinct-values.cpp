class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>mp;

        for(int i : nums){
            mp[i]++;
        }

        vector<int> ans;

        while(!mp.empty()){
            vector<int>v;
            for(auto&p : mp){
                ans.push_back(p.first);
                p.second--;
                if(p.second == 0){
                    v.push_back(p.first);
                }
            }
            for(int i : v){
                mp.erase(i);
            }
        }
        return ans;
    }
};