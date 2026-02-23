class Solution {
public:
    static inline void normalize(string& s){
        const char c0=s[0];
        for(char& c: s){
            c-=c0-'a';
            if (c<'a') c+=26;
        }
    }
    static long long countPairs(vector<string>& words) {
        const int n=words.size(), m=words[0].size();
        unordered_map<string, int> mp;
        mp.reserve(n);
        long long cnt=0;
        for(string& s : words){
            normalize(s);
            cnt+=mp[s]++;
        }
        return cnt;
    }
};