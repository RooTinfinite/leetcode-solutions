class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.length();
        if(t.length()!=n) return false;
        int mp[26]={0};
        int maxi=k/26;
        int rem=k%26;
        for(int i=0;i<n;i++){
            if(t[i]==s[i]) continue;
            int p=t[i]-s[i];
            if(p<0) p+=26;
            mp[p]++;
            if(mp[p]>(maxi+(p<=rem))) return false;
        }
        return true;
    }
};