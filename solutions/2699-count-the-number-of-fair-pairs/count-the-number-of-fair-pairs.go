func countFairPairs(nums []int, lower int, upper int) int64 {
    sort.Ints(nums)
    return countPairs(nums, upper) - countPairs(nums, lower - 1)
}

func countPairs(nums []int, target int) int64 {
    var count int64 = 0
    left, right := 0, len(nums) - 1
    
    for left < right {
        if nums[left] + nums[right] > target {
            right--
        } else {
            count += int64(right - left)
            left++
        }
    }
    return count
}