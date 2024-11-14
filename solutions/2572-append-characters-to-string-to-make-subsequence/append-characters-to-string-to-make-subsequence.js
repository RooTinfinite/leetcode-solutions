/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var appendCharacters = function(s, t) {
    let sIndex = 0, tIndex = 0;
    const sLength = s.length, tLength = t.length;
    
    while (sIndex < sLength && tIndex < tLength) {
        if (s[sIndex] === t[tIndex]) {
            tIndex++;
        }
        sIndex++;
    }
    
    return tLength - tIndex;
};