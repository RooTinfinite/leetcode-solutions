import "sort"

type sumFenwick struct {
	count []int
	sum   []int64
	size  int
	total int64
}

func (f *sumFenwick) add(index, delta int, value int64) {
	f.size += delta
	f.total += int64(delta) * value
	for index < len(f.count) {
		f.count[index] += delta
		f.sum[index] += int64(delta) * value
		index += index & -index
	}
}

func (f *sumFenwick) largest(k int) int64 {
	if k == 0 {
		return 0
	}
	drop := f.size - k
	if drop == 0 {
		return f.total
	}

	index := 0
	var prefix int64
	step := 1
	for step<<1 < len(f.count) {
		step <<= 1
	}
	for ; step > 0; step >>= 1 {
		next := index + step
		if next < len(f.count) && f.count[next] <= drop {
			drop -= f.count[next]
			prefix += f.sum[next]
			index = next
		}
	}
	return f.total - prefix
}

func maxSum(nums []int, length int, k int) int64 {
	n := len(nums)
	var windowSum int64
	for _, value := range nums[:length] {
		windowSum += int64(value)
	}
	if k == 0 || length == n {
		best := windowSum
		for right := length; right < n; right++ {
			windowSum += int64(nums[right]) - int64(nums[right-length])
			if windowSum > best {
				best = windowSum
			}
		}
		return best
	}

	order := make([]int, n)
	for i := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return nums[order[i]] < nums[order[j]]
	})

	rank := make([]int, n)
	var globalBest int64
	for i, index := range order {
		rank[index] = i + 1
		if i >= n-length {
			globalBest += int64(nums[index])
		}
	}
	if k >= length || k >= n-length {
		return globalBest
	}

	inside := sumFenwick{
		count: make([]int, n+1),
		sum:   make([]int64, n+1),
	}
	outside := sumFenwick{
		count: make([]int, n+1),
		sum:   make([]int64, n+1),
	}

	topOutside := 0
	for i, value := range nums {
		if i < length {
			inside.add(rank[i], 1, int64(value))
		} else {
			outside.add(rank[i], 1, int64(value))
			if rank[i] > n-length {
				topOutside++
			}
		}
	}

	best := int64(-1 << 63)
	for left := 0; ; left++ {
		if topOutside <= k {
			return globalBest
		}

		current := inside.largest(length-k) + outside.largest(k)
		if current > best {
			best = current
		}

		right := left + length
		if right == n {
			break
		}

		inside.add(rank[left], -1, int64(nums[left]))
		outside.add(rank[left], 1, int64(nums[left]))
		outside.add(rank[right], -1, int64(nums[right]))
		inside.add(rank[right], 1, int64(nums[right]))

		if rank[left] > n-length {
			topOutside++
		}
		if rank[right] > n-length {
			topOutside--
		}
	}
	return best
}