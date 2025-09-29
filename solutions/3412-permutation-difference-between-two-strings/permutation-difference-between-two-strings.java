class Solution {
    public int findPermutationDifference(String s, String t) {
        int n = s.length();
        int[] pos = new int[26];
        for (int i = 0; i < n; i++) {
            pos[s.charAt(i) - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.abs(pos[t.charAt(i) - 'a'] - i);
        }
        return ans;
    }
}