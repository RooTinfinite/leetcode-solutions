class Solution {
    private int parseNumber(String abbreviation, int startPos) {
        int number = 0;
        while (startPos < abbreviation.length() && 
               Character.isDigit(abbreviation.charAt(startPos))) {
            number = number * 10 + (abbreviation.charAt(startPos) - '0');
            startPos++;
        }
        return number;
    }
    
    public boolean validWordAbbreviation(String word, String abbreviation) {
        int wordPos = 0, abbrPos = 0;
        
        while (abbrPos < abbreviation.length() && wordPos < word.length()) {
            if (Character.isLetter(abbreviation.charAt(abbrPos))) {
                if (abbreviation.charAt(abbrPos) != word.charAt(wordPos)) {
                    return false;
                }
                wordPos++;
                abbrPos++;
            } else {
                if (abbreviation.charAt(abbrPos) == '0') {
                    return false;
                }
                
                int skipCount = parseNumber(abbreviation, abbrPos);
                abbrPos += String.valueOf(skipCount).length();
                wordPos += skipCount;
            }
        }
        
        return abbrPos == abbreviation.length() && wordPos == word.length();
    }
}