/*
Approach:
1. Convert problem into prefix difference: diff[i] = (#1s - #0s)
2. Two cases:
   - diff == 0 -> no swap needed
   - diff == +/- 2 -> fixed using one swap
3. Use hashmaps to track first occurrence and availability of characters outside.
*/

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> z(n), o(n), diff(n);
        int cnt0 = 0, cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
            z[i] = cnt0;
            o[i] = cnt1;
            diff[i] = o[i] - z[i];
        }

        int maxLen = 0;
        unordered_map<int, int> ind, ind0, ind1; 
        ind[0] = -1;

        for (int i = 0; i < n; i++) {
            int pref = diff[i];

            if (ind.count(pref)) {
                maxLen = max(maxLen, i - ind[pref]);
            }
            
            // Case: diff = -2 (need a '1')
            if (ind.count(pref + 2)) { 
                int j = ind[pref + 2];
                int sub1s = o[i] - (j >= 0 ? o[j] : 0);

                if (cnt1 > sub1s) maxLen = max(maxLen, i - j);
                else if (ind1.count(pref + 2)) maxLen = max(maxLen, i - ind1[pref + 2]);
            }

            // Case: diff = +2 (need a '0')
            if (ind.count(pref - 2)) { 
                int j = ind[pref - 2];
                int sub0s = z[i] - (j >= 0 ? z[j] : 0);

                if (cnt0 > sub0s) maxLen = max(maxLen, i - j);
                else if (ind0.count(pref - 2)) maxLen = max(maxLen, i - ind0[pref - 2]);
            }
            
            if (!ind.count(pref)) ind[pref] = i;
            if (!ind0.count(pref) && z[i] > 0) ind0[pref] = i;
            if (!ind1.count(pref) && o[i] > 0) ind1[pref] = i;
        }
        return maxLen;
    }
};