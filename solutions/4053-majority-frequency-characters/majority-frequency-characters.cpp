class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26,0);
    for(int i = 0 ; i < s.size();i++){
        freq[s[i]-'a']++;
    }
    vector<int>freq1(101,0);
    for(int i = 0 ; i < 26; i ++){
        if(freq[i]!=0)
        freq1[freq[i]]++;
    }
    int cnt = 0;
    int index  = 0;
    for(int i = 0 ; i < 101;i++) {
        if(freq1[i] >= cnt) {
            cnt = freq1[i];
            index = i;
        }
    }
    string ss = "";
    for(int i = 0 ; i < 26; i++){
        if(freq[i] == index)
            ss= ss + (char)(i+'a');
    }
    return ss;
    }
};