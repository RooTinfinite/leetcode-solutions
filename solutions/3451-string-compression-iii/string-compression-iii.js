/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    let comp = "";
    let n = word.length;
    for(let i = 0; i < n; ) {
        let char = word[i];
        let k = i + 9;
        let length = 0; 
        while(i < n && i < k && word[i] == char) {
            length += 1;
            i += 1;
        }
        comp += String(length) + char;
    }
    return comp;
};