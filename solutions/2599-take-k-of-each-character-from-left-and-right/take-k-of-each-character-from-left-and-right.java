class Solution {
    public int takeCharacters(String s, int k) {
        int[] d = new int[3], h = new int[3];
        for (char c : s.toCharArray()) d[c - 'a']++;
        for (int i = 0; i < 3; i++) if ((d[i] -= k) < 0) return -1;
        
        int m = 0, l = 0;
        for (int r = 0; r < s.length(); r++) {
            h[s.charAt(r) - 'a']++;
            while (l <= r && h[s.charAt(r) - 'a'] > d[s.charAt(r) - 'a']) h[s.charAt(l++) - 'a']--;
            m = Math.max(m, r - l + 1);
        }
        return s.length() - m;
    }
}