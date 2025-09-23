class Solution {
public:
    bool isFascinating(int n) {
        string temp=to_string(n);

        int val1=2*n,val2=3*n;

        string s=temp+to_string(val1)+to_string(val2);

        unordered_map<char,int>mp;
        for(char &ch:s){
            if(ch=='0') return false;
            mp[ch]++;
            if(mp[ch]>1) return false;
        }
        return true;
    }
};