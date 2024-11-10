func merge(nums1 []int, m int, nums2 []int, n int) {
    for j, i := 0, m; j < n; j, i = j+1, i+1 {
        nums1[i] = nums2[j]
    }
    sort.Ints(nums1)
}