class Solution {
public:
    int minLights(vector<int>& l) {
        int n = l.size();
        vector<int> li(n, 0);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (mx > 0)
                li[i] = -1;

            if (l[i] > 0) {
                mx = max(l[i], mx - 1);
                if (mx > 0)
                    li[i] = -1;
            } else {
                if (mx > 0)
                    li[i] = -1;
                mx--;
            }
        }

        mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (mx > 0)
                li[i] = -1;

            if (l[i] > 0) {
                mx = max(l[i], mx - 1);
                if (mx > 0)
                    li[i] = -1;
            } else {
                if (mx > 0)
                    li[i] = -1;
                mx--;
            }
        }

        int count = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (li[i] != -1) {
                count++;
            } else {
                ans += (count + 2) / 3;
                count = 0;
            }
        }

        if (count)
            ans += (count + 2) / 3;

        return ans;
    }
};