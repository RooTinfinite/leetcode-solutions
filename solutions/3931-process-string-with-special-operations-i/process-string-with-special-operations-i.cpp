class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0 && !(s[i]>=97 && s[i]<=122))
            continue;
            
            if(s[i]>=97 && s[i]<=122)
            ans.push_back(s[i]);

            else if(s[i]=='*')
            ans.pop_back();
            else if(s[i]=='#')
            ans+=ans;
            else if(s[i]=='%')
            reverse(ans.begin(),ans.end());

        }
        return ans;
    }
};