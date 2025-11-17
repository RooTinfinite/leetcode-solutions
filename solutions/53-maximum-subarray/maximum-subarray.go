func maxSubArray(nums []int) int {
    // Our helper function is designed to solve this problem for
    // any array - so just call it using the entire input!
    return findBestSubarray(nums, 0, len(nums)-1)
}

func findBestSubarray(nums []int, left int, right int) int {
    // Base case - empty array.
    if left > right {
        return -2147483648
    }
    mid := (left + right) / 2
    curr := 0
    bestLeftSum := 0
    bestRightSum := 0
    // Iterate from the middle to the beginning.
    for i := mid - 1; i >= left; i-- {
        curr += nums[i]
        if bestLeftSum < curr {
            bestLeftSum = curr
        }
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0
    for i := mid + 1; i <= right; i++ {
        curr += nums[i]
        if bestRightSum < curr {
            bestRightSum = curr
        }
    }
    // The bestCombinedSum uses the middle element and the best possible sum from each half.
    bestCombinedSum := nums[mid] + bestLeftSum + bestRightSum
    // Find the best subarray possible from both halves.
    leftHalf := findBestSubarray(nums, left, mid-1)
    rightHalf := findBestSubarray(nums, mid+1, right)
    // The largest of the 3 is the answer for any given input array.
    if bestCombinedSum < leftHalf {
        bestCombinedSum = leftHalf
    }
    if bestCombinedSum < rightHalf {
        bestCombinedSum = rightHalf
    }
    return bestCombinedSum
}