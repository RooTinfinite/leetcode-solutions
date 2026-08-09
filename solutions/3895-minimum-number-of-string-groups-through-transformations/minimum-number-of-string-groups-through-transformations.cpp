class Solution {
public:
    const int MOD = 1e9 + 7;
    const int RADIX = 26;
    typedef long long ll;

    ll powr(ll a, ll b) {

        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    ll calcHash(string& s) {
        if (s.empty()) // For 1 length words odd indices will be empty
            return 0;

        int m = s.length();
        string doubled = s + s;
        ll currHash = 0;

        ll mul = powr(RADIX, m);

        for (int i = 0; i < m; i++) // Calculate hash up to original length of string 
            currHash = (currHash * RADIX + (doubled[i] - 'a')) % MOD;

        ll minHash = currHash;

        for (int i = 1; i < m; i++) { // Calculate subsequent hashesh by sliding the window and tracking the min of all hashes
            currHash = (currHash * RADIX) % MOD;
            ll subtract = ((doubled[i - 1] - 'a') * mul) % MOD;
            currHash = (currHash - subtract + MOD) % MOD;
            currHash = (currHash + (doubled[i + m - 1] - 'a')) % MOD;

            minHash = min(minHash, currHash);
        }

        return minHash;
    }

    int minimumGroups(vector<string>& words) {

        int n = words.size();
        set<pair<ll, ll>> groups; //set to store unique even and hodd hash pair

        for (int i = 0; i < n; i++) {
            string str = words[i], odStr = "", evStr = "";

            for (int j = 0; j < str.length(); j += 2) {
                evStr.push_back(str[j]);
            }

            for (int j = 1; j < str.length(); j += 2) {
                odStr.push_back(str[j]);
            }

            ll evHash = calcHash(evStr);
            ll odHash = calcHash(odStr);

            groups.insert({evHash, odHash}); //only insert unique hash pair  
        }

        return groups.size(); //size of set gives total no. of groups
    }
};