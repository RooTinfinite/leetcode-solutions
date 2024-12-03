// JavaScript

var addSpaces = function(s, spaces) {
    const result = new Array(s.length + spaces.length);
    let writePos = 0;
    let readPos = 0;
    
    for (const spacePos of spaces) {
        while (readPos < spacePos) {
            result[writePos++] = s[readPos++];
        }
        result[writePos++] = ' ';
    }
    
    while (readPos < s.length) {
        result[writePos++] = s[readPos++];
    }
    
    return result.join('');
};