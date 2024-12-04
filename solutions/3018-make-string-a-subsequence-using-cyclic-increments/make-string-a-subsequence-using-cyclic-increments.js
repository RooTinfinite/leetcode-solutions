// JavaScript

var canMakeSubsequence = function(source, target) {
    let targetIdx = 0;
    const targetLen = target.length;
    
    for (let currChar of source) {
        if (targetIdx < targetLen && 
            ((target.charCodeAt(targetIdx) - currChar.charCodeAt(0) + 26) % 26 <= 1)) {
            targetIdx++;
        }
    }
    
    return targetIdx === targetLen;
};