class Solution {
    public long countValidSubstrings(String s) {
        int n = s.length();
        int left = 0;
        long res = 0;

        for (int right = 0; right < n; right++) {
            if (right >= 2 &&
                    s.charAt(right - 2) == 'a' &&
                    s.charAt(right - 1) == 'b' &&
                    s.charAt(right) == 'c') {
                left = Math.max(left, right - 1);
            }

            res += right - left + 1;
        }

        return res;
    }
}