class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";

        string ans;
        int count = 0;

        while (n > 0) {
            if (count && count % 3 == 0) 
                ans += '.';
            ans += (n % 10 + '0');
            n /= 10;
            count++;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};