class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        if(n==1) return 0;

        int i=1;
        int cnt = 0;
        while(i<n) {
            if(abs(word[i]-word[i-1]) <= 1) {
                cnt++;
                i++;
            }
            i++;
        }

        return cnt;
    }
};