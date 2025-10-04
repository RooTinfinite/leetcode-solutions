class Solution {
    // time = O(n), space = O(1)
    public String answerString(String word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.length();
        int i = 0, j = 1;
        while (j < n) {
            int k = 0;
            while (j + k < n && word.charAt(i + k) == word.charAt(j + k)) k++;
            if (j + k < n && word.charAt(i + k) < word.charAt(j + k)) {
                int t = i;
                i = j;
                j = Math.max(j + 1, t + k + 1);
            } else j = j + k + 1;
        }
        return word.substring(i, Math.min(n, i + n - numFriends + 1));
    }
}