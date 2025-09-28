class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = s;
        for(int i = 0; i < n; i++){
            int c = s.at(i)- 'a';
            for(int j = 0; j < 26; j++){
                int d = min(abs(c - j), 26 - abs(c - j));
                if(d <= k){
                    t.at(i) = char(j + 'a');
                    k -= d;
                    break;
                }
            }
        }
        return t;
    }
};