public class Solution {
    public bool IsValid(string word) {
        if (word.Length < 3) {
            return false;
        }
        bool hasVowel = false;
        bool hasConsonant = false;
        foreach (char c in word) {
            if (char.IsLetter(c)) {
                char ch = char.ToLower(c);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!char.IsDigit(c)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}