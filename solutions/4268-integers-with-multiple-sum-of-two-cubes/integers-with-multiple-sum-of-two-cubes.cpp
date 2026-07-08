class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        vector<int> ans;

        int limit = cbrt(n);

        for (long long i = 1; i <= limit; i++) {
            long long i3 = i * i * i;

            for (long long j = i; j <= limit; j++) {
                long long sum = i3 + j * j * j;

                if (sum > n) break;   //stop

                mp[sum]++;
            }
        }

        for (auto &it : mp) {
            if (it.second >= 2) {   //at least two distinct pairs (a, b)
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};