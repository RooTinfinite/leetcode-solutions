func search(nums []int, target int) int {
    n := len(nums)
    left, right := 0, n-1
    for left <= right {
        mid := left + (right-left)/2
        // Case 1: find target
        if nums[mid] == target {
            return mid
        }
        // Case 2: subarray on mid's left is sorted
        if nums[mid] >= nums[left] {
            if target >= nums[left] && target < nums[mid] {
                right = mid - 1
            } else {
                left = mid + 1
            }
        } else {
            // Case 3: subarray on mid's right is sorted
            if nums[mid] <= nums[right] {
                if target <= nums[right] && target > nums[mid] {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
        }
    }
    return -1
}