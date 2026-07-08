class Solution {
    public boolean wordPatternMatch(String pattern, String s) {
        String[] symbols = new String[26];
        Arrays.fill(symbols, "");
        Set<String> wordSet = new HashSet<>();

        return isMatch(s, 0, pattern, 0, symbols, wordSet);
    }

    private boolean isMatch(String s, int sIndex, String pattern, int pIndex,
            String[] symbols, Set<String> wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True if and only if also reached end of s
        }

        // Get current pattern character
        char symbol = pattern.charAt(pIndex);

        // This symbol already has an associated word
        if (!symbols[symbol - 'a'].equals("")) {
            String word = symbols[symbol - 'a'];
            // Check if we can use it to match s[sIndex...sIndex + word.length()]
            if (!s.startsWith(word, sIndex)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1, symbols, wordSet);
        }

        // Count the number of spots the remaining symbols in the pattern take
        int filledSpots = 0;
        for (int i = pIndex + 1; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            filledSpots += symbols[p - 'a'].equals("") ? 1 : symbols[p - 'a'].length();
        }

        // This symbol does not have an associated word
        for (int k = sIndex + 1; k <= s.length() - filledSpots; k++) {
            String newWord = s.substring(sIndex, k);
            if (wordSet.contains(newWord))
                continue;
            // Create or update it
            symbols[symbol - 'a'] = newWord;
            wordSet.add(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbols, wordSet)) {
                return true;
            }
            // Backtracking
            symbols[symbol - 'a'] = "";
            wordSet.remove(newWord);
        }
        // No mappings were valid
        return false;
    }
}