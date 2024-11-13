public class Solution {
    private int ParseNumber(string abbreviation, int startPos) {
        int number = 0;
        while (startPos < abbreviation.Length && char.IsDigit(abbreviation[startPos])) {
            number = number * 10 + (abbreviation[startPos] - '0');
            startPos++;
        }
        return number;
    }
    
    public bool ValidWordAbbreviation(string word, string abbreviation) {
        int wordPos = 0, abbrPos = 0;
        
        while (abbrPos < abbreviation.Length && wordPos < word.Length) {
            if (char.IsLetter(abbreviation[abbrPos])) {
                if (abbreviation[abbrPos] != word[wordPos]) {
                    return false;
                }
                wordPos++;
                abbrPos++;
            } else {
                if (abbreviation[abbrPos] == '0') {
                    return false;
                }
                
                int skipCount = ParseNumber(abbreviation, abbrPos);
                abbrPos += skipCount.ToString().Length;
                wordPos += skipCount;
            }
        }
        
        return abbrPos == abbreviation.Length && wordPos == word.Length;
    }
}