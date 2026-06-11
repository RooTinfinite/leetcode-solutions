func firstUniqueFreq(nums []int) int {
    if len(nums) == 0 {
        return -1
    }

    counter := make(map[int]int)
    for _, num := range nums {
        counter[num]++
    }

    freq := make(map[int]int)
    for _, count := range counter {
        freq[count]++
    }

    for _, num := range nums {
        count := counter[num]
        if freq[count] == 1 {
            return num
        }
    }

    return -1
}