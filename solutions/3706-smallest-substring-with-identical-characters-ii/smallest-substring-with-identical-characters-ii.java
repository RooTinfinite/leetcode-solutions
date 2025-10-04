import java.util.*;

class Solution {
    private int check(List<Integer> gp, int m) {
        int res = 0;
        for (int x : gp) {
            if (x <= m) continue;
            res += x / (m + 1);
        }
        return res;
    }

    public int minLength(String s, int numOps) {
        int n = s.length();
        int a1 = 0, a2 = 0;
        String ok = "01";
        List<Integer> gp = new ArrayList<>();
        char prev = s.charAt(0);
        int curr = 0;
        int ans = 0;

        // Calculate `a1`, `a2`, and `gp` groups
        for (int i = 0; i < n; i++) {
            a1 += (s.charAt(i) != ok.charAt(i % 2)) ? 1 : 0;
            a2 += (s.charAt(i) != ok.charAt((i % 2) ^ 1)) ? 1 : 0;
            if (prev != s.charAt(i)) {
                gp.add(curr);
                curr = 0;
            }
            curr++;
            ans = Math.max(ans, curr);
            prev = s.charAt(i);
        }
        gp.add(curr);

        // If either `a1` or `a2` is less than or equal to `numOps`, return 1
        if (a1 <= numOps || a2 <= numOps) {
            return 1;
        }

        // Binary search to find the minimum length
        int l = 2, r = ans;
        while (l <= r) {
            int m = (l + r) / 2;
            int bruh = check(gp, m);
            if (bruh <= numOps) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
}