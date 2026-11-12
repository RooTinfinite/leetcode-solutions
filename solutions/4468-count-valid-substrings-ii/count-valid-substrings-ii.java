class Solution {
    public long countValidSubstrings(String s) {
        long ans = 0;
        int lastA = -1;
        int start = -1;
        int bad = -1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'a') {
                lastA = i;
            } else if (ch == 'b' && lastA != -1) {
                start = lastA;
            } else if (ch == 'c' && start != -1) {
                bad = Math.max(bad, start);
            }
            ans += i - bad;
        }
        return ans;
    }
}