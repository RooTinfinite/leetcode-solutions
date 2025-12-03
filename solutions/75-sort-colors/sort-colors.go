func sortColors(nums []int) {
    /*
       Dutch National Flag problem solution.
    */
    p0, curr := 0, 0
    p2 := len(nums) - 1
    for curr <= p2 {
        if nums[curr] == 0 {
            nums[curr], nums[p0] = nums[p0], nums[curr]
            curr++
            p0++
        } else if nums[curr] == 2 {
            nums[curr], nums[p2] = nums[p2], nums[curr]
            p2--
        } else {
            curr++
        }
    }
}