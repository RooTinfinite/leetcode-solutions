string toBinary(long long n) {
    if (n == 0) return "0";
    string res;
    while (n > 0) {
        res.push_back('0' + (n & 1));
        n >>= 1LL;
    }
    ranges::reverse(res);
    return res;
}

long long toDecimal(string &bin) {
    long long res = 0;
    for (char c : bin)
        res = 1LL * res * 2 + (c - '0');
    return res;
}

class Solution {
public:
    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;
        int ans = 2;
        string str, rstr, temp;

        auto getCount = [&] (int op) -> int {
            int low = 1, high = 1e8, ansT = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                str = toBinary(mid);
                rstr = str; ranges::reverse(rstr);
                if (op == 0) temp = str + rstr;
                else if (op == 1) temp = str + "0" + rstr;
                else temp = str + "1" + rstr;
                long long mxx = toDecimal(temp);
                if (mxx <= n) ansT = mid, low = mid+1;
                else high = mid-1;
            }
            return ansT;
        };

        ans += getCount (0) + getCount (1) + getCount (2);
        return ans;
    }
};