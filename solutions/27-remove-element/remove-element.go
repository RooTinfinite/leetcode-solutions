func removeElement(nums []int, val int) int {
    writeIndex := 0
    for readIndex := 0; readIndex < len(nums); readIndex++ {
        if nums[readIndex] != val {
            nums[writeIndex] = nums[readIndex]
            writeIndex++
        }
    }
    return writeIndex
}