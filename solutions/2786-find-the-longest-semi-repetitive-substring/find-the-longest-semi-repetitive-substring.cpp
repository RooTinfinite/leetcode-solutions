class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if(s.size()==1) return 1;
        int l=0,r=1, ans=0,cnt=0;
        while(r<s.size()){
            cnt+=(s[r]==s[r-1]);
            while(l<=r && cnt>1){
                cnt-=(s[l]==s[l+1]);
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};