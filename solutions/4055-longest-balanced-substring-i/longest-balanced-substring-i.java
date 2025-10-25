class Solution {
    public int longestBalanced(String s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'a']++;
                if (isBalanced(freq, freq[s.charAt(j) - 'a'])) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    boolean isBalanced(int[] freq, int tar) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0 && freq[i] != tar)
                return false;
        }
        return true;
    }
}