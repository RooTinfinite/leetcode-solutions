class Solution {
public:
    int almostPalindromic(string s) {
       int n=s.length();
       vector<vector<bool>>isPalindrome(n,vector<bool>(n,false));
       for(int len=1;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(len==1)isPalindrome[i][j]=true;
            else if(len==2){
                if(s[i]==s[j])isPalindrome[i][j]=true;
                else isPalindrome[i][j]=false;
            }else{
                if(s[i]==s[j])isPalindrome[i][j]=isPalindrome[i+1][j-1];
            }
        }
       }
       int ans=2;
       vector<vector<bool>>isAlmostPalindrome(n,vector<bool>(n,false));
       for(int i=0;i<n;i++)isAlmostPalindrome[i][i]=true;
       for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(len==2)isAlmostPalindrome[i][j]=true;
            else{
                if(s[i]==s[j])isAlmostPalindrome[i][j]=
                                      isAlmostPalindrome[i+1][j-1];
                else if(isPalindrome[i+1][j])isAlmostPalindrome[i][j]=true;
                else if(isPalindrome[i][j-1])isAlmostPalindrome[i][j]=true;
            }
            if(isAlmostPalindrome[i][j])ans=max(ans,len);
        }
       }
       return ans;
    }
};