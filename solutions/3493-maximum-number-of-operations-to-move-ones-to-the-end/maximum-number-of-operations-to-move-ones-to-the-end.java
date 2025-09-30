public class Solution {
    public int maxOperations(String s) {
        int x = 0, c = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                c++;
            } else if (s.charAt(i) == '0') {
                if (i == n - 1 || s.charAt(i + 1) == '1') {
                    x += c;
                }
            }
        }
        return x;
    }
}