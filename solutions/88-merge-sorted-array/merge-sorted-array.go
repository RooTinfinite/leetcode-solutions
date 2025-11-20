func merge(nums1 []int, m int, nums2 []int, n int) {
    // Set p1 and p2 to point to the end of their respective arrays.
    p1 := m - 1
    p2 := n - 1
    // And move p backward through the array, each time writing
    // the largest value pointed at by p1 or p2.
    for p := m + n - 1; p >= 0; p-- {
        if p2 < 0 {
            break
        }
        if p1 >= 0 && nums1[p1] > nums2[p2] {
            nums1[p] = nums1[p1]
            p1--
        } else {
            nums1[p] = nums2[p2]
            p2--
        }
    }
}