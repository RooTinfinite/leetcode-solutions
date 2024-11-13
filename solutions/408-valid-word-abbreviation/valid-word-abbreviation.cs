public class Solution {
    public bool ValidWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.Length && j < abbr.Length) {
            if (char.IsDigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j < abbr.Length && char.IsDigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;
            } else {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }
        return i == word.Length && j == abbr.Length;
    }
}