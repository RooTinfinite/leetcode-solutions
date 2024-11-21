// JavaScript

var firstUniqChar = function(s) {
    let firstUnique = Infinity;
    
    for (let charCode = 97; charCode <= 122; charCode++) {
        const currChar = String.fromCharCode(charCode);
        
        if (s.includes(currChar)) {
            if (s.indexOf(currChar) === s.lastIndexOf(currChar)) {
                firstUnique = Math.min(firstUnique, s.indexOf(currChar));
            }
        }
    }
    
    return firstUnique === Infinity ? -1 : firstUnique;
};