func merge(nums1 []int, m int, nums2 []int, n int) {
    k := m + n - 1
    i := m - 1
    j := n - 1
    
    for j >= 0 {
        if i >= 0 && nums1[i] > nums2[j] {
            nums1[k] = nums1[i]
            i--
        } else {
            nums1[k] = nums2[j]
            j--
        }
        k--
    }
}