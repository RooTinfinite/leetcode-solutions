class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool b=0;
        string rem;
        for(auto &s:source){
          string ss=rem;
            for(int i=0;i<s.length();i++){
                if(b){
                    if(s[i]=='*' and i+1<s.length() and s[i+1]=='/')
                    {
                        i++;
                        b=0;
                    }
                }
                else{
                    if(s[i]=='/' and i+1<s.length() and s[i+1]=='*'){
                        i++;
                        b=1;
                    }
                    else if(s[i]=='/' and i+1<s.length() and s[i+1]=='/')
                        break;
                    else
                        ss.push_back(s[i]);
                }
            }
            if(b)
                rem=ss;
            else if(ss.length()>0) {
                ans.push_back(ss);
                rem="";
            }
        }
        return ans;
    }
};