class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0}, n = s.length();
        for(int i = 0; i < n; ++i) ++freq[s[i] - 'a'];
        string res;
        while(res.length() < n){
            for(int i = 0; i < 26; ++i){
                if(freq[i]-- > 0) res.push_back(i + 'a');
            }
            for(int i = 25; i >= 0; --i){
                if(freq[i]-- > 0) res.push_back(i + 'a');
            }
        }
        return res;
    }
};