class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0' && s[i+1]=='1') return false;
        }
        return true;
    }
};