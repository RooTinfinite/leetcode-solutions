class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        for(int i=0;i<s.length()-1;i++){
            int j=i;
            while(s[j]==s[i+1]){
                i++;
            }
            if(i-j+1>=3){
                ans.push_back({j,i});
            }
        }
        return ans;
    }
};