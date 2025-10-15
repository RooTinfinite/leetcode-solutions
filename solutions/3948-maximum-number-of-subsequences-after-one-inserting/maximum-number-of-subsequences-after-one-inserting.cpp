class Solution {
public:
    long long countLCT(const string& s) {
        long long l = 0, lc = 0, lct = 0;
        for (char ch : s) {
            if (ch == 'L') l++;
            else if (ch == 'C') lc += l;
            else if (ch == 'T') lct += lc;
        }
        return lct;
    }

    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> prefixL(n + 1, 0);  
        vector<int> suffixT(n + 1, 0);  
        for (int i = 0; i < n; ++i) {
            prefixL[i + 1] = prefixL[i] + (s[i] == 'L' ? 1 : 0);
        }
        for (int i = n - 1; i >= 0; --i) {
            suffixT[i] = suffixT[i + 1] + (s[i] == 'T' ? 1 : 0);
        }

        long long base = countLCT(s);
        long long maxLCT = base;

        // Insert 'L' at the beginning
        string l_inserted = "L" + s;
        maxLCT = max(maxLCT, countLCT(l_inserted));

        // Insert 'T' at the end
        string t_inserted = s + "T";
        maxLCT = max(maxLCT, countLCT(t_inserted));

        // Try inserting 'C' at the best position
        long long maxExtra = 0;
        for (int i = 0; i <= n; ++i) {
            long long extra = 1LL * prefixL[i] * suffixT[i];
            maxExtra = max(maxExtra, extra);
        }
        maxLCT = max(maxLCT, base + maxExtra);

        return maxLCT;
    }
};