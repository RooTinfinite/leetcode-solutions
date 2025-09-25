class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int len = n;
        string ans = "";
        for(int i=0; i<=n+1; i++) ans += "1";
        string temp = ans;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(s[j] == '1') cnt++;
                if(cnt == k){
                    string x = s.substr(i,j-i+1);
                    if(j-i+1 < len){
                        ans = x;
                        len = j-i+1;
                    }
                    else if(j-i+1 == len){
                        ans = min(ans,x);
                    }
                    break;
                }
            }
        }
        if(ans == temp) return "";
        return ans;
        
    }
};