class Solution {
public:
    int maxSubstrings(string word) {
        int last[26] = {};
        int n = word.length(), res = 0, mask = 0;
        for (int i = 0; i < n; i++){
            int c = word[i] - 'a';
            if ((mask & (1 << c)) == 0){
                last[c] = i;
                mask |= (1 << c); // mark as seen
            }
            else if (i - last[c] + 1 >= 4) {
                res++;
                mask = 0; // reset mask                
            }
        }
        return res;
    }
};