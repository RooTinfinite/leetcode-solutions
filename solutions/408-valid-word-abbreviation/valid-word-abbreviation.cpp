class Solution {
private:
    int parseNumber(const string& abbreviation, int startPos) {
        int number = 0;
        while (startPos < abbreviation.length() && isdigit(abbreviation[startPos])) {
            number = number * 10 + (abbreviation[startPos] - '0');
            startPos++;
        }
        return number;
    }
    
public:
    bool validWordAbbreviation(string word, string abbreviation) {
        int wordPos = 0, abbrPos = 0;
        
        while (abbrPos < abbreviation.length() && wordPos < word.length()) {
            if (isalpha(abbreviation[abbrPos])) {
                if (abbreviation[abbrPos] != word[wordPos]) {
                    return false;
                }
                wordPos++;
                abbrPos++;
            } else {
                if (abbreviation[abbrPos] == '0') {
                    return false;
                }
                
                int skipCount = parseNumber(abbreviation, abbrPos);
                abbrPos += to_string(skipCount).length();
                wordPos += skipCount;
            }
        }
        
        return abbrPos == abbreviation.length() && wordPos == word.length();
    }
};