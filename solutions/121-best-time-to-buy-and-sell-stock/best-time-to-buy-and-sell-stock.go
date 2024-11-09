func maxProfit(nums []int) int {
    minPro := math.MaxInt32
    maxPro := 0
    for _, num := range nums {
        minPro = min(num, minPro)
        maxPro = max(maxPro, num - minPro)
    }
    return maxPro
}