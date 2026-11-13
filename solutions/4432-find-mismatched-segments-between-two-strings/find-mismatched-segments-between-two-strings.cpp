class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.length();
        if(n==0){
            return {};
        }
        vector<vector<string>>ans;
        int i=0;
        while(i<n){
            if(s1[i]!=s2[i]){
            int st=i;
            while(i<n&&s1[i]!=s2[i]){
                i++;
            }
            ans.push_back({s1.substr(st,i-st),s2.substr(st,i-st)});
            }else{
                i++;
            }
        }
        return ans;
    }
};