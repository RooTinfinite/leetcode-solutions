class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        vector<int> f3(3, 0), f6(6, 0), f9(9, 0);
        vector<vector<int>> f7(6, vector<int>(7, 0));
        
        int pref3 = 0, pref6 = 0, pref9 = 0, pref7Val = 0;
        f3[0] = 1;
        f6[0] = 1;
        f9[0] = 1;
        f7[0][0] = 1;
        
        vector<int> f = {1, 5, 4, 6, 2, 3};
        
        for (int j = 0; j < n; j++) {
            int d = s[j] - '0';
            pref3 = (pref3 + d) % 3;
            pref6 = (pref6 * 4 + d) % 6;
            pref9 = (pref9 + d) % 9;
            pref7Val = (pref7Val * 10 + d) % 7;
            
            if (d == 0) {
            } else if (d == 1 || d == 2 || d == 5) {
                ans += (j + 1);
            } else if (d == 3) {
                ans += f3[pref3];
            } else if (d == 6) {
                int needed = pref6;
                for (int r = 0; r < 6; r++) {
                    if ((4 * r) % 6 == needed) {
                        ans += f6[r];
                    }
                }
            } else if (d == 9) {
                ans += f9[pref9];
            } else if (d == 7) {
                for (int r = 0; r < 6; r++) {
                    int t = ((j + 1 - r) % 6 + 6) % 6;  
                    int needed = (pref7Val * f[t]) % 7;
                    ans += f7[r][needed];
                }
            } else if (d == 4) {
                int contrib = 1;
                if (j >= 1) {
                    int num = (s[j - 1] - '0') * 10 + d;
                    if (num % 4 == 0) {
                        contrib += j;
                    }
                }
                ans += contrib;
            } else if (d == 8) {
                int contrib = 1;
                if (j >= 1) {
                    int num = (s[j - 1] - '0') * 10 + d;
                    if (num % 8 == 0) {
                        contrib += 1;
                    }
                }
                if (j >= 2) {
                    int num = (s[j - 2] - '0') * 100 
                              + (s[j - 1] - '0') * 10 + d;
                    if (num % 8 == 0) {
                        contrib += (j - 1);
                    }
                }
                ans += contrib;
            }
            
            f3[pref3]++;
            f6[pref6]++;
            f9[pref9]++;
            f7[(j + 1) % 6][pref7Val]++;
        }
        
        return ans;
    }
};