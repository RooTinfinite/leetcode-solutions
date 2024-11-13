// JavaScript

var validWordAbbreviation = function(word, abbreviation) {
    function parseNumber(abbreviation, startPos) {
        let number = 0;
        while (startPos < abbreviation.length && /\d/.test(abbreviation[startPos])) {
            number = number * 10 + parseInt(abbreviation[startPos]);
            startPos++;
        }
        return number;
    }
    
    let wordPos = 0, abbrPos = 0;
    
    while (abbrPos < abbreviation.length && wordPos < word.length) {
        if (/[a-zA-Z]/.test(abbreviation[abbrPos])) {
            if (abbreviation[abbrPos] !== word[wordPos]) {
                return false;
            }
            wordPos++;
            abbrPos++;
        } else {
            if (abbreviation[abbrPos] === '0') {
                return false;
            }
            
            const skipCount = parseNumber(abbreviation, abbrPos);
            abbrPos += String(skipCount).length;
            wordPos += skipCount;
        }
    }
    
    return abbrPos === abbreviation.length && wordPos === word.length;
};
