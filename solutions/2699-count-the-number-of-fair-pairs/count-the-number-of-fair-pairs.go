func binSearch(nums []int, l, r, target int) int {
    for l <= r {
        m := l + (r-l)/2
        if nums[m] >= target {
            r = m - 1
        } else {
            l = m + 1
        }
    }
    return r
}

func countFairPairs(nums []int, lower int, upper int) int64 {
    sort.Ints(nums)
    var res int64
    for i := 0; i < len(nums); i++ {
        low := lower - nums[i]
        up := upper - nums[i]
        res += int64(binSearch(nums, i+1, len(nums)-1, up+1) - 
                     binSearch(nums, i+1, len(nums)-1, low))
    }
    return res
}