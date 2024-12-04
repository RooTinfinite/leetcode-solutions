class Solution {
    func canMakeSubsequence(_ source: String, _ target: String) -> Bool {
        let srcLen = source.count
        let tgtLen = target.count
        var targetChar = target.first!
        
        var srcIdx = 0
        var tgtIdx = 0
        let sourceArray = Array(source)
        let targetArray = Array(target)
        
        while srcIdx < srcLen && tgtIdx < tgtLen {
            let srcChar = sourceArray[srcIdx]
            
            if srcChar == targetChar ||
               srcChar.asciiValue! + 1 == targetChar.asciiValue! ||
               (srcChar == "z" && targetChar == "a") {
                tgtIdx += 1
                if tgtIdx < tgtLen {
                    targetChar = targetArray[tgtIdx]
                }
            }
            srcIdx += 1
        }
        
        return tgtIdx == tgtLen
    }
}