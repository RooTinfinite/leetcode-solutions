class Solution {

    public int numOfStrings(String[] patterns, String word) {
        int res = 0;
        for (String pattern : patterns) {
            if (check(pattern, word)) {
                res++;
            }
        }
        return res;
    }

    private boolean check(String pattern, String word) {
        int m = pattern.length();
        int n = word.length();

        // generate the prefix array of the pattern
        int[] pi = new int[m];
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++;
            }
            pi[i] = j;
        }

        // using prefix arrays for matching
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && word.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }
            if (word.charAt(i) == pattern.charAt(j)) {
                j++;
            }
            if (j == m) {
                return true;
            }
        }
        return false;
    }
}