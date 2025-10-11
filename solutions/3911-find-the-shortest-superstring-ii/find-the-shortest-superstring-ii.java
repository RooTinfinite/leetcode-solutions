class Solution {
    public String shortestSuperstring(String s1, String s2) {
        if (s1.contains(s2)) {
            return s1;
        }
        if (s2.contains(s1)) {
            return s2;
        }
        int a = check(s1, s2);
        int b = check(s2, s1);
        if (a > b) {
            return combine(s1, s2, a);
        } else {
            return combine(s2, s1, b);
        }
    }

    private int check(String x, String y) {
        int maxOverlap = Math.min(x.length(), y.length());
        for (int i = maxOverlap; i > 0; i--) {
            String suffix = x.substring(x.length() - i);
            String prefix = y.substring(0, i);
            if (suffix.equals(prefix)) {
                return i;
            }
        }
        return 0;
    }

    private String combine(String x, String y, int maxOverlap) {
        return x + y.substring(maxOverlap);
    }
}