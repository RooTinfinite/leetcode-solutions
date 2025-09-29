func countCompleteDayPairs(hours []int) int64 {
    var ans int64 = 0
    count := make([]int, 24)
    
    for _, hour := range hours {
        ans += int64(count[(24 - hour % 24) % 24])
        count[hour % 24]++
    }
    
    return ans
}