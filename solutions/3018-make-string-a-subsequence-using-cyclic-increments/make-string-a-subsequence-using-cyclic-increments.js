// JavaScript

var canMakeSubsequence = function(source, target) {
    const srcLen = source.length;
    const tgtLen = target.length;
    let targetChar = target[0];
    
    let srcIdx = 0, tgtIdx = 0;
    while (srcIdx < srcLen && tgtIdx < tgtLen) {
        const srcChar = source[srcIdx];
        
        if (srcChar === targetChar || 
            String.fromCharCode(srcChar.charCodeAt(0) + 1) === targetChar ||
            (srcChar === 'z' && targetChar === 'a')) {
            tgtIdx++;
            if (tgtIdx < tgtLen) {
                targetChar = target[tgtIdx];
            }
        }
        
        srcIdx++;
    }
    
    return tgtIdx === tgtLen;
};