var canMakeSubsequence = function(source, target) {
    let srcLen = source.length;
    let tgtLen = target.length;
    let srcIdx = 0;
    let tgtIdx = 0;
    
    while (srcIdx < srcLen && tgtIdx < tgtLen) {
        if (source[srcIdx] === target[tgtIdx] || 
            (source[srcIdx] === 'z' && target[tgtIdx] === 'a') || 
            (source.charCodeAt(srcIdx) + 1 === target.charCodeAt(tgtIdx))) {
            srcIdx++;
            tgtIdx++;
        } else {
            srcIdx++;
        }
    }
    return tgtIdx === tgtLen;
};