func maxEqualRowsAfterFlips(mat [][]int) int {
    patFreq := make(map[string]int)
    
    for _, row := range mat {
        pattern := make([]byte, len(row))
        if row[0] == 0 {
            for i, bit := range row {
                pattern[i] = byte(bit) + '0'
            }
        } else {
            for i, bit := range row {
                pattern[i] = byte(bit ^ 1) + '0'
            }
        }
        patFreq[string(pattern)]++
    }
    
    maxFreq := 0
    for _, freq := range patFreq {
        if freq > maxFreq {
            maxFreq = freq
        }
    }
    return maxFreq
}