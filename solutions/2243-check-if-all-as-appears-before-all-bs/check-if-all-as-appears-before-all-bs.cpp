class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int b = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                if(b == 1) return false;
            }
            else b = 1;
        }
        return true;
    }
};