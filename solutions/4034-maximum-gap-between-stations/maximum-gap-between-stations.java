
class Solution {
    public int maximumGap(String skill, String station) {
        int n = skill.length();
        int m = station.length();

        int[] left = new int[n];
        int pos = 0;

        for (int i = 0; i < n; i++) {
            while (station.charAt(pos) != skill.charAt(i)) {
                pos++;
            }

            left[i] = pos;
            pos++;
        }

        if (n == 1) {
            return 0;
        }

        int[] right = new int[n];
        pos = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            while (station.charAt(pos) != skill.charAt(i)) {
                pos--;
            }

            right[i] = pos;
            pos--;
        }

        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            res = Math.max(res, right[i + 1] - left[i]);
        }

        return res;
    }
}