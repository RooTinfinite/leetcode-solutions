type FindSumPairs struct {
	nums1 []int
	nums2 []int
	cnt   map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	cnt := make(map[int]int)
	for _, num := range nums2 {
		cnt[num]++
	}
	return FindSumPairs{
		nums1: nums1,
		nums2: nums2,
		cnt:   cnt,
	}
}

func (this *FindSumPairs) Add(index int, val int) {
	oldVal := this.nums2[index]
	this.cnt[oldVal]--
	this.nums2[index] += val
	this.cnt[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
	ans := 0
	for _, num := range this.nums1 {
		rest := tot - num
		ans += this.cnt[rest]
	}
	return ans
}