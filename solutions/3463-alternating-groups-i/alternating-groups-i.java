class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int res = 0;
        int n = colors.length;
        for (int i = 0; i < n; ++i) {
            int pre = colors[i];
            int cur = colors[(i + 1) % n];
            int nxt = colors[(i + 2) % n];
            if (pre != cur && cur != nxt) ++res;
        }
        return res;
    }
}