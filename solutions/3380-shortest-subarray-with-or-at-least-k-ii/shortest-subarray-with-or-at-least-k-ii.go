func minimumSubarrayLength(nums []int, k int) int {
    ans := math.MaxInt32
    s := 0
    left := 0
    cnt := make([]int, 32)
    
    for right, num := range nums {
        s |= num
        i := 0
        temp := num
        for temp > 0 {
            cnt[i] += temp % 2
            temp /= 2
            i++
        }
        
        for s >= k && left <= right {
            if right-left+1 < ans {
                ans = right - left + 1
            }
            temp = nums[left]
            i = 0
            for temp > 0 {
                if temp%2 == 1 {
                    cnt[i]--
                    if cnt[i] == 0 {
                        s ^= 1 << i
                    }
                }
                temp /= 2
                i++
            }
            left++
        }
    }
    
    if ans == math.MaxInt32 {
        return -1
    }
    return ans
}