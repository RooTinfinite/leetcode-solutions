const inf = int64(1e18)

func div(x int64, k int) int64 {
    if x >= 0 {
        return x / int64(k)
    }
    return -((-x) / int64(k))
}

func op(x int64, k int, flag int64) int64 {
    if flag != 0 {
        return x * int64(k)
    }
    return div(x, k)
}

func f(v []int, k int, flag int64) int64 {
    n := len(v)
    dp1 := make([]int64, n)
    dp2 := make([]int64, n)
    dp3 := make([]int64, n)

    dp1[0] = int64(v[0])
    dp2[0] = op(int64(v[0]), k, flag)
    dp3[0] = -inf

    for i := 1; i < n; i++ {
        val := op(int64(v[i]), k, flag)
        dp1[i] = max(int64(v[i]), dp1[i-1]+int64(v[i]))
        dp2[i] = max(val, dp1[i-1]+val, dp2[i-1]+val)
        dp3[i] = max(dp2[i-1]+int64(v[i]), dp3[i-1]+int64(v[i]), dp2[i])
    }

    ans := -inf
    for i := 0; i < n; i++ {
        ans = max(ans, dp1[i], dp2[i], dp3[i])
    }
    return ans
}

func maxSubarraySum(v []int, k int) int64 {
    return max(f(v, k, 0), f(v, k, 1))
}