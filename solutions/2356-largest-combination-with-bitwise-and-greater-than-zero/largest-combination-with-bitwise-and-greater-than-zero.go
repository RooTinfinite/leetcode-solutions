const BitMax = 24
func largestCombination(candidates []int) int {
    maxSet := 1
    mask := 1
    
    for shift := 0; shift < BitMax; shift++ {
        count := 0
        for _, num := range candidates {
            if num&mask != 0 {
                count++
            }
        }
        if maxSet < count {
            maxSet = count
        }
        mask <<= 1
    }
    return maxSet
}