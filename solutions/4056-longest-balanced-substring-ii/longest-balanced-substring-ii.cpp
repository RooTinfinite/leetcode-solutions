typedef long long ll;
class Solution {
public:
    ll n;
    ll key(vector<ll>& cnt)
    {
        return cnt[0] + cnt[1] * (n + 1) + cnt[2] * (n + 1) * (n + 1); 
    }

    int longestBalanced(string s) {
        vector<ll> cnt(3, 0);
        n = s.size();
        unordered_map<ll, int> mp[8];
        vector<ll> cur(3, 0);
        int ans = 0;
        for (int j = 0; j < 8; j++) mp[j][0] =-1;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int x = c - 'a';
            cnt[x]++;
            for (int m = 7; m > 0; m--)
            {
                ll mind = n;
                for (int b = 0; b < 3; b++)
                {
                    int bit = 1 << b;
                    if ((bit & m) == bit) mind = min(mind, cnt[b]);
                    cur[b] = cnt[b];
                }
                for (int b = 0; b < 3; b++)
                {
                    int bit = 1 << b;
                    if ((bit & m) == bit) cur[b] -= mind;
                }
                
                ll k = key(cur);
                if (mp[m].count(k) > 0)  ans = max(ans, i - mp[m][k]); 
                else  mp[m][k] = i; 
            }
        }
        return ans;
    }
};