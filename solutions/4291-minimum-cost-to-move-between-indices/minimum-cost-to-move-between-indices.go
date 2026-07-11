import "math"

func minCost(nums []int, queries [][]int) []int {
    n := len(nums)
    length := len(queries)

    pre := make([]int64, n)
    suff := make([]int64, n)

    for i := 0; i < n-1; i++ {
        diffFromRight := int64(nums[i+1] - nums[i])

        var diffFromLeft int64
        if i > 0 {
            diffFromLeft = int64(nums[i] - nums[i-1])
        } else {
            diffFromLeft = math.MaxInt64
        }

        if diffFromRight < diffFromLeft {
            pre[i+1] = pre[i] + 1
        } else {
            pre[i+1] = pre[i] + diffFromRight
        }
    }

    for i := n - 1; i > 0; i-- {
        diffFromLeft := int64(nums[i] - nums[i-1])

        var diffFromRight int64
        if i < n-1 {
            diffFromRight = int64(nums[i+1] - nums[i])
        } else {
            diffFromRight = math.MaxInt64
        }

        if diffFromLeft <= diffFromRight {
            suff[i-1] = suff[i] + 1
        } else {
            suff[i-1] = suff[i] + diffFromLeft
        }
    }

    ans := make([]int, length)

    for i := 0; i < length; i++ {
        l := queries[i][0]
        r := queries[i][1]

        if l <= r {
            ans[i] = int(pre[r] - pre[l])
        } else {
            ans[i] = int(suff[r] - suff[l])
        }
    }

    return ans
}