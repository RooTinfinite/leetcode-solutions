class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        for (index, j) in (m..<m+n).enumerated() {
            nums1[j] = nums2[index]
        }
        nums1.sort()
    }
}