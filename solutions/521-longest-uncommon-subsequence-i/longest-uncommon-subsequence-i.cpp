class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()==b.size()){
            if(a==b)return -1;
        }else{
            if(a.size()<b.size())return b.size();
        }
        return a.size();
    }
};