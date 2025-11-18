// Golang Solution
func permuteUnique(nums []int) [][]int {
    results := [][]int{}
    counter := make(map[int]int)
    for _, num := range nums {
        counter[num]++
    }
    var backtrack func(comb []int, N int)
    backtrack = func(comb []int, N int) {
        if len(comb) == N {
            tmp := make([]int, len(comb))
            copy(tmp, comb)
            results = append(results, tmp)
            return
        }
        for num, count := range counter {
            if count == 0 {
                continue
            }
            comb = append(comb, num)
            counter[num]--
            backtrack(comb, N)
            counter[num]++
            comb = comb[:len(comb)-1]
        }
    }
    backtrack([]int{}, len(nums))
    return results
}