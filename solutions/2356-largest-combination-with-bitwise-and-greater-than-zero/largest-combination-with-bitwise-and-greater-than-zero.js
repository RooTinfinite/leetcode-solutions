/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    const BitMax = 24;
    let maxSet = 1;
    let mask = 1;
    
    for (let shift = 0; shift < BitMax; shift++) {
        let count = 0;
        for (let num of candidates) {
            if (num & mask) {
                count++;
            }
        }
        maxSet = Math.max(maxSet, count);
        mask <<= 1;
    }
    
    return maxSet;
};