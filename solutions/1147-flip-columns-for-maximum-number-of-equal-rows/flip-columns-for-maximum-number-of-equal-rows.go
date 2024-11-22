func maxEqualRowsAfterFlips(matrix [][]int) int {
    count := make(map[string]int)
    
    for _, row := range matrix {
        key := make([]byte, len(row))
        for i, n := range row {
            if row[0] == 1 {
                key[i] = byte('0' + (1 - n))
            } else {
                key[i] = byte('0' + n)
            }
        }
        count[string(key)]++
    }
    
    maxCount := 0
    for _, v := range count {
        if v > maxCount {
            maxCount = v
        }
    }
    return maxCount
}