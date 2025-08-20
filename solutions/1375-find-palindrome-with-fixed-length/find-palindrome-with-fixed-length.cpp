int foo = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

static const auto _ = [](){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    void form(long long& ans, int intLength, long long num) {
        int count = intLength/2;
        long long ans2 = ans;
        long long temp = 0;
        if (intLength%2 == 1)
            ans2 /= 10;
        while (count--) {
            temp = 10*temp + (ans2%10);
            ans2 /= 10;
        }
        ans = ans*(pow(10, (intLength)/2)) + temp;
        return;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        long long num = 1;
        num *= pow(10, (intLength-1)/2);
        long long n = queries.size();
        vector<long long> ans(n);
        for (long long i=0; i<n; i++) {
            if (num + queries[i] > 10*num) {
                ans[i] = -1;
                continue;
            }
            ans[i] += num + (queries[i]-1);
            form(ans[i], intLength, num);
        }
        return ans;
    }
};