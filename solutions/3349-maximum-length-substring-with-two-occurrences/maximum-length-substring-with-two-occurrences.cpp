class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0; 
        unordered_map<char, int> freq; 
        for (int i = 0, ii = 0; i < s.size(); ++i) {
            ++freq[s[i]]; 
            while (freq[s[i]] == 3) --freq[s[ii++]]; 
            ans = max(ans, i-ii+1); 
        }
        return ans; 
    }
};