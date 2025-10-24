class Solution {
public:
    int maxDistance(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (words[i] != words[n - 1]) {
                res = n - i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (words[i] != words[0]) {
                res = max(res, i + 1);
                break;
            }
        }
        return res;
    }
};