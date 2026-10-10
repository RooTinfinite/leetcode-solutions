func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minSumSquareDiff(nums1 []int, nums2 []int, k1 int, k2 int) int64 {
	k := k1 + k2
	n := len(nums1)
	maxDif := 0
	for i := 0; i < n; i++ {
		nums1[i] = abs(nums1[i] - nums2[i])
		if nums1[i] > maxDif {
			maxDif = nums1[i]
		}
	}

	l, r, res := 0, maxDif, 0
	for l <= r {
		mid := (l + r) / 2
		sum := 0
		for _, num := range nums1 {
			if num > mid {
				sum += num - mid
			}
		}
		if sum <= k {
			r = mid - 1
			res = mid
		} else {
			l = mid + 1
		}
	}

	for _, num := range nums1 {
		if num > res {
			k -= num - res
		}
	}

	sort.Slice(nums1, func(i, j int) bool { return nums1[i] > nums1[j] })
	ans := int64(0)
	for _, num := range nums1 {
		diff := num
		if res < num {
			diff = res
		}
		if k > 0 && diff > 0 {
			diff--
			k--
		}
		ans += int64(diff) * int64(diff)
	}
	return ans
}