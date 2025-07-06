class Solution {
public:
    int minFlips(string target) {
        int n=target.length();
        vector<char> comp;
        comp.push_back(target[0]);
        for(int i=1;i<n;i++)
        {
            if(target[i]!=target[i-1])
            {
                comp.push_back(target[i]);
            }
        }
        if(comp[0]=='0')
        return comp.size()-1;
        else
        return comp.size();
    }
};