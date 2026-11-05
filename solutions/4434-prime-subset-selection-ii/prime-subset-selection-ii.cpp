class Solution {
public:
    vector<int> sievesAlgorithm(int n, int s) {
        vector<bool> notPrimes(n + 1, false);
        notPrimes[0] = true;
        notPrimes[1] = true;

        vector<int> ans;

        for (int i = 2; i * i <= n; i++) {
            if (!notPrimes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    notPrimes[j] = true;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (!notPrimes[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    vector<int> knapSack(vector<int>& primes, int s) {
        vector<vector<int>> dp(s + 1);
        vector<int> mp(s + 1, false);
        mp[0] = true;

        for (auto p : primes) {
            for (int w = s; w >= p; w--) {
                if (mp[w - p]) {
                    vector<int> temp = dp[w - p];
                    temp.push_back(p);

                    if (!mp[w]) {
                        mp[w] = true;
                        dp[w] = temp;
                    } else if (dp[w].size() == temp.size() &&
                               temp < dp[w]) {
                        dp[w] = temp;
                    } else if (dp[w].size() > temp.size()) {
                        dp[w] = temp;
                    }
                }
            }
        }

        for (int i = s; i > 0; i--) {
            if (mp[i]) {
                return dp[i];
            }
        }

        return {};
    }

    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes = sievesAlgorithm(n, s);
        return knapSack(primes, s);
    }
};