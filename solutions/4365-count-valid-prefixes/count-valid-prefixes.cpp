class Solution {
public:
    int countValidPrefixes(string s) {
        int balance = 0, ans = 0;

        for(char ch : s){
            balance = (ch == '1') ? balance + 1 : balance - 1;

            if(balance >= -1 && balance <= 1)
                ans++;
        }

        return ans;
    }
};