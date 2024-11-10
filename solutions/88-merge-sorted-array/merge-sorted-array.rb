def merge(nums1, m, nums2, n)
    n.times do |j|
        nums1[m + j] = nums2[j]
    end
    nums1.sort!
end