
class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        int res = 0;

        for (int i = 0; i < n; i++) {
            bool seen1[27] = {false};
            int l[27] = {0};
            int r[27] = {0};
            int ans1 = 0;

            for (int j = i; j >= 0; j--) {
                int c = s[j] - 'a';

                if (!seen1[c]) {
                    seen1[c] = true;
                    ans1++;
                }

                l[ans1]++;
            }

            bool seen2[27] = {false};
            int ans2 = 0;

            for (int k = i + 1; k < n; k++) {
                int c = s[k] - 'a';

                if (!seen2[c]) {
                    seen2[c] = true;
                    ans2++;
                }

                r[ans2]++;
            }

            for (int x = 1; x <= 26; x++) {
                res += l[x] * r[x];
            }
        }

        return res;
    }
};