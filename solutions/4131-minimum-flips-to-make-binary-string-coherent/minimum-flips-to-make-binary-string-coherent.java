class Solution {
    public int minFlips(String s) {
        int[] f = {0, -1};
        int n = s.length();

        for (int i = 0; i < n; i++)
            f[s.charAt(i) & 1]++;

        if (f[0] == 0 || f[1] == -1) return 0;

        return Math.min(
            f[0],
            f[1] - (s.charAt(0) & s.charAt(n - 1) & 1)
        );
    }
}