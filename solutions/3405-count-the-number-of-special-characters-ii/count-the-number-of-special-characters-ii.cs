public class Solution {
    public int NumberOfSpecialChars(string word) {
        int[] lastLow = new int[26];
        int[] firstUp = new int[26];
        Array.Fill(lastLow, -1);
        Array.Fill(firstUp, -1);
        for (int i = 0; i < word.Length; i++) {
            char c = word[i];
            if (char.IsLower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 &&
                lastLow[i] < firstUp[i]) {
                ans++;
            }
        }
        return ans;
    }
}