class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        int k = s.length();
        unordered_map<int,int>freq;
        
        for(int i = 0; i<k; i++){
            freq[s[i]-'0']++;
        }

        int minfreq =  INT_MAX;
        for(auto it : freq){
            minfreq = min(minfreq,it.second);
        }
        int result = 10;
        for(auto it : freq){
            if(it.second == minfreq){
                result = min(result, it.first);
            }
        }
return result;
    }
};