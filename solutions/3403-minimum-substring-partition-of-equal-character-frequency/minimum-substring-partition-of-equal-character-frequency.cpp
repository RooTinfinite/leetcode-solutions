class Solution {
public:

    bool check(unordered_map<int, int> &freq){
        int prevFreq = freq.begin()->second;
        for(auto &i: freq){
            if(i.second != prevFreq){
                return false;
            }
            
            prevFreq = i.second;
        }

        return true;
    }
    
    int minPart(int index, string s, vector<int> &dp){
        if(index >= (s.size())){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int ans = 1e9;

        unordered_map<int, int> freq;
        for(int i=index; i<s.size(); i++){
            freq[s[i] - 'a']++;

            if(check(freq)){
                ans = min(ans, (minPart(i+1, s, dp)+1));
            }
        }

        dp[index] = ans;

        return dp[index];
    } 

    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size()+5, -1);
        return minPart(0, s, dp);
    }
};