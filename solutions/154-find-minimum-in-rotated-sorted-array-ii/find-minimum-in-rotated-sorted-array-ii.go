func findMin(nums []int) int {
    low, high := 0, len(nums)-1

    for low < high {
        pivot := low + (high-low)/2
        if nums[pivot] < nums[high] {
            high = pivot
        } else if nums[pivot] > nums[high] {
            low = pivot + 1
        } else {
            high -= 1
        }
    }
    return nums[low]
}