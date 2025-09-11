class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1, mp2;
        // for target characters
        for(auto x :target){
            mp1[x]++;
        }
        // for s characters now
        for(char x : s){
            mp2[x]++;
        }
        // now let us check how many target can be formed in s
        int mini = INT_MAX;

        for(auto x : mp1){
            int freq = x.second;
            char ch = x.first;
            if(mp2[ch] < x.second) return 0;
            mini = min(mp2[ch]/freq, mini);
        }
        return mini;
    }
};