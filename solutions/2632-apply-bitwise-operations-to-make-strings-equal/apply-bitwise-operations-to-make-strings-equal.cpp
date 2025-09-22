class Solution {
public:
    bool makeStringsEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        if(s1.length()==1){
            if(s2=="1")return false;
        }
        int x = 0, y = 0;
        for(auto &i: s1)x += (i=='1');
        for(auto &i: s2)y += (i=='1');
        int n = s1.length();
        if((x && !y)||(!x && y)){
            return false;
        }
        return true;
    }
};