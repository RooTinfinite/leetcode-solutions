class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        for (int i=0;i<word.size();i+=k){
            string b="";
            for (int j=0;j<k;j++){b+=word[i+j];}
            mp[b]++;
        }
        string ms="";
        int o=-1;
        for (auto it:mp){if (it.second>o){o=it.second;ms=it.first;}}
        o=0;
        for (int i=0;i<word.size();i+=k){
            string b="";
            for (int j=0;j<k;j++){b+=word[i+j];}
            if (b!=ms){o++;}
        }
        return o;
    }
};