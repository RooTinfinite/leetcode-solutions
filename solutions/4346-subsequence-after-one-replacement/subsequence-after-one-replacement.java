class Solution {
    public boolean canMakeSubsequence(String s, String t) {
        if (s.length() > t.length()) return false;

        int n = s.length(), m = t.length();

        if (n == 0) return true;

        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, -1);

        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && t.charAt(p) != s.charAt(i)) {
                p++;
            }
            if (p == m) break;
            left[i] = p++;
        }

        if (left[n - 1] != -1) return true;

        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && t.charAt(p) != s.charAt(i)) {
                p--;
            }
            if (p < 0) break;
            right[i] = p--;
        }

        for (int i = 0; i < n; i++) {
            if ((i == 0 || left[i - 1] != -1) &&
                (i == n - 1 || right[i + 1] != -1)) {

                int L = (i == 0) ? -1 : left[i - 1];
                int R = (i == n - 1) ? m : right[i + 1];

                if (L + 1 < R) {
                    return true;
                }
            }
        }

        return false;
    }
}