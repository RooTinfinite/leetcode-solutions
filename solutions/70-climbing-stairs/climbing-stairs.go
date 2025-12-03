// Golang
func climbStairs(n int) int {
    if n <= 1 {
        return 1
    }
    if n == 2 {
        return 2
    }
    oneStepBefore := 2
    twoStepsBefore := 1
    allWays := 0
    for i := 2; i < n; i++ {
        allWays = oneStepBefore + twoStepsBefore
        twoStepsBefore = oneStepBefore
        oneStepBefore = allWays
    }
    return allWays
}