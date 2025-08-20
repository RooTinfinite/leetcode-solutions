class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string token,ans;
        while(getline(ss,token,' ')){
            for(char &ch:token) ch=tolower(ch);

            if(token.length()>2){
                token[0]=toupper(token[0]);
            }
            if(!ans.empty()) ans+=' ';
            ans+=token;
        }
        return ans;
    }
};