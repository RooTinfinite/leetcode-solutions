class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        string s1="";
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<indices.size();j++)
            {
                if(indices[j]==i)
                {
                    s1=s1+s[j];
                    break;
                }
            }
        }
        return s1;
    }
};