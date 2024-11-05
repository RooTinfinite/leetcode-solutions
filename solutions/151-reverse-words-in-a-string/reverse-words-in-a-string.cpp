class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string temp;
        // vector<string> str;
        s="";
        while(ss>>temp)
        {
            reverse(temp.begin(),temp.end());
            s += " " + temp;
        }
        // s = str[0];
        // for(int i = 1; i<str.size(); i++)
        // {
        //     s += " ";
        //     s += str[i];
        // }
        return s.substr(1); 
    }
};