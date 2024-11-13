// JavaScript


var validWordAbbreviation = function(word, abbr) {
    let i = 0, j = 0;
   
    while (i < word.length && j < abbr.length) {
        if (/\d/.test(abbr[j])) {
            if (abbr[j] === '0') return false;
            let num = 0;
            while (j < abbr.length && /\d/.test(abbr[j])) {
                num = num * 10 + Number(abbr[j]);
                j++;
            }
            i += num;
        } else {
            if (word[i] !== abbr[j]) return false;
            i++;
            j++;
        }
    }
    return i === word.length && j === abbr.length;
};