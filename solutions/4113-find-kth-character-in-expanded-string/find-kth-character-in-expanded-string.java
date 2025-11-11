class Solution {
    // time = O(n), space = O(n)
    public char kthCharacter(String s, long k) {
        String[] strs = s.split(" ");
        int n = strs.length;
        k++;
        char res = ' ';
        for (int i = 0, t = 0; i < n; i++) {
            int m = strs[i].length();
            long tot = (1L + m) * m / 2;
            if (tot >= k) {
                int x = ((int)Math.sqrt(8 * k + 1) - 1) / 2;
                long y = (1L + x) * x / 2;
                if (y < k) res = strs[i].charAt(x);
                else res = strs[i].charAt(x - 1);
                break;
            } else {
                k -= tot;
                if (k == 1) break;
                k--;
            }
        }
        return res;
    }
}