function largestCombination(candidates: number[]): number {
    const BitMax: number = 24;
    let maxSet: number = 1;
    let mask: number = 1;
    
    for (let shift = 0; shift < BitMax; shift++) {
        let count: number = 0;
        for (let num of candidates) {
            if (num & mask) {
                count++;
            }
        }
        maxSet = Math.max(maxSet, count);
        mask <<= 1;
    }
    
    return maxSet;
}