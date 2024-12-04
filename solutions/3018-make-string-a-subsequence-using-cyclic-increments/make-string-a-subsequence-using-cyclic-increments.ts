// TypeScript

function canMakeSubsequence(source: string, target: string): boolean {
    let targetIdx = 0;
    const targetLen = target.length;
    
    for (const currChar of source) {
        if (targetIdx < targetLen && 
            (target.charCodeAt(targetIdx) - currChar.charCodeAt(0) + 26) % 26 <= 1) {
            targetIdx++;
        }
    }
    return targetIdx === targetLen;
}