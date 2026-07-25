#define ll long long
class Solution {
public:
    //i and j are pointers on w1 and w2 respectively
    //k is the target char under consideration
    //we keep a mask that tells if one character from both strings is taken or not
    //00=neither strings used,10=w1 used only,01=w2 used only and 11=both used
    //suppose we were at target[k] and indices on w1 and w2 were i and j
    //choice1:pick a matching char at an index >=i from w1
    //choice 2:pick a matching char at an index >=j from w2
    ll dp[105][105][105][4];
    ll MOD=1e9+7;
    ll func(int i,int j,int k,string& w1,string& w2,string& target,int mask)
    {
        if(k==target.size())
        {
            return mask==3?1LL:0LL;
        }
        if(dp[i][j][k][mask]!=-1) return dp[i][j][k][mask];
        int ans=0;
        char ch=target[k];
        //choose from w1
        for(int index=i;index<w1.size();index++)
        {
            if(w1[index]==ch)
            {
                ans=(ans+func(index+1,j,k+1,w1,w2,target,(mask|(1<<1))))%MOD;
            }
        }
        //chppse from w2
        for(int index=j;index<w2.size();index++)
        {
            if(w2[index]==ch)
            {
                ans=(ans+func(i,index+1,k+1,w1,w2,target,(mask|(1<<0))))%MOD;
            }
        }
        return dp[i][j][k][mask]=ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        int ans=func(0,0,0,word1,word2,target,0);
        return ans;
    }
};