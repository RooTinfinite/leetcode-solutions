class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s =to_string(num);
        int n=s.size();
        if(n==1)
        return true;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' && (i==0 ||i==n-1))
            return false;
        }
        string v=s;
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(v==s)
        return true;
        return false;
        
    }
};