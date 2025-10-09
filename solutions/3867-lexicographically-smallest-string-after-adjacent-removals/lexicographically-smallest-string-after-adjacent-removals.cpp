class Solution {
public:
//foxed (right to left while lex)
    string lexicographicallySmallestString(string s) {
        
        int n= s.size();
        
        vector<vector<int>> range(n+5, vector<int>(n+5, 0));

        for(int i=n-1; i>=0; i--)
        {
           for(int j=0; j<n; j++)
           {
             if(j<=i)continue;
             if(j-i+1== 2){
                if(abs(s[i]-s[j])==1 || abs(s[i]-s[j])==25)range[i][j]=1;
                continue;
             }
             if((j-i+1)%2==1){
                continue;
             }
             if(i+1<n && j-1>=0 && ((j-i+1)%2==0) &&  range[i+1][j-1] && (abs(s[i]-s[j])==1 || abs(s[i]-s[j])==25))
             range[i][j]=1;
             else{
                 for(int k=i+1; k<j; k++)
                 {
                    if(range[i][k] && range[k+1][j])
                    range[i][j]=1;
                 }
             }
           }
        }

        vector<string> dp(n);

        for(int i=n-1; i>=0; i--)
        {
            string mini= s.substr(i, n-i);

            for(int j=i; j<n; j++)
            {
                string a= "";
                if(range[i][j]==0)
                  a=  s.substr(i, j-i+1);
                if(j+1<n)a+= dp[j+1];

                mini= min(mini, a);
            }
            dp[i]= mini;
        }
    
        return dp[0];

    }
};