func backtrack(nums []int, cur []int, ans *[][]int) {
    if len(cur) == len(nums) {
        copied := make([]int, len(cur))
        copy(copied, cur)
        *ans = append(*ans, copied)
        return
    }
    for _, num := range nums {
        exists := false
        for _, val := range cur {
            if val == num {
                exists = true
                break
            }
        }
        if !exists {
            cur = append(cur, num)
            backtrack(nums, cur, ans)
            cur = cur[:len(cur)-1]
        }
    }
}

func permute(nums []int) [][]int {
    ans := make([][]int, 0)
    backtrack(nums, []int{}, &ans)
    return ans
}