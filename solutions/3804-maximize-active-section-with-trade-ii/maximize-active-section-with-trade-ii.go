func maxActiveSectionsAfterTrade(s string, queries [][]int) []int {
	n, m := len(s), len(queries)
	cnt1 := 0
	for _, c := range s {
		if c == '1' {
			cnt1++
		}
	}
	// left[i]: represents the length of the continuous block ending at position i, which is the same as s[i]
	left := make([]int, n)
	// right[i]: represents the length of the continuous block starting at position i with the same value as s[i]
	right := make([]int, n)

	for i := 0; i < n; i++ {
		if i > 0 && s[i-1] == s[i] {
			left[i] = left[i-1] + 1
		} else {
			left[i] = 1
		}
	}
	for i := n - 1; i >= 0; i-- {
		if i < n-1 && s[i+1] == s[i] {
			right[i] = right[i+1] + 1
		} else {
			right[i] = 1
		}
	}

	ans := make([]int, m)
	for i := range ans {
		ans[i] = -1
	}
	block_size := int(math.Sqrt(float64(n)))
	// query with length greater than block length
	longQueries := make([][4]int, 0, m)

	bruteForce := func(l, r int) int {
		i := l
		best := 0
		prev := math.MinInt32

		for i <= r {
			start := i
			for i <= r && s[i] == s[start] {
				i++
			}
			if s[start] == '0' {
				cur := i - start
				if prev != math.MinInt32 && prev+cur > best {
					best = prev + cur
				}
				prev = cur
			}
		}
		return best
	}

	for i := 0; i < m; i++ {
		l, r := queries[i][0], queries[i][1]
		if r - l + 1 > block_size {
			longQueries = append(longQueries, [4]int{l / block_size, l, r, i})
		} else {
			// queries shorter than block length, brute-force calculation
			ans[i] = cnt1 + bruteForce(l, r)
		}
	}

	// sort by the ID of the block where the left endpoint is located as the first keyword, and by the right endpoint as the second keyword
	sort.Slice(longQueries, func(i, j int) bool {
		if longQueries[i][0] != longQueries[j][0] {
			return longQueries[i][0] < longQueries[j][0]
		}
		return longQueries[i][2] < longQueries[j][2]
	})

	// use an array to simulate a double-ended queue, expanding from the middle to avoid frequent memory allocation
	subZeroBlocks := make([]int, n)
	head, tail := n/2, n/2
	L, R, bestGain := 0, 0, 0

	for i := 0; i < len(longQueries); i++ {
		bid, l, r, qid := longQueries[i][0], longQueries[i][1], longQueries[i][2], longQueries[i][3]
		if i == 0 || bid > longQueries[i-1][0] {
			// traverse to a new block, perform initialization operations
			L = (bid+1)*block_size - 1 // L is initialized to the right endpoint of the block
			R = (bid + 1) * block_size  // R is initialized to the left endpoint of the next block
			head, tail = n/2, n/2
			bestGain = 0
		}

		for R <= r {
			sz := right[R]
			if r-R+1 < sz {
				sz = r - R + 1
			}
			if s[R] == '0' {
				if tail > head && s[R-1] == '0' {
					subZeroBlocks[tail-1] += sz
				} else {
					subZeroBlocks[tail] = sz
					tail++
				}
				if tail-head >= 2 {
					val := subZeroBlocks[tail-1] + subZeroBlocks[tail-2]
					if val > bestGain {
						bestGain = val
					}
				}
			}
			R += sz
		}

		// before moving the left endpoint L, backup the value of bestGain
		tmp_bestGain := bestGain
		// value of the first element of subZeroBlocks before moving the left endpoint
		tmp_firstValue := -1
		if tail > head {
			tmp_firstValue = subZeroBlocks[head]
		}
		// the number of digits added from the left during the process of recording the movement of the left endpoint L
		cnt := 0

		for L >= l {
			sz := left[L]
			if L-l+1 < sz {
				sz = L - l + 1
			}
			if s[L] == '0' {
				if tail > head && s[L+1] == '0' {
					subZeroBlocks[head] += sz
				} else {
					head--
					subZeroBlocks[head] = sz
					cnt++
				}
				if tail-head >= 2 {
					val := subZeroBlocks[head] + subZeroBlocks[head+1]
					if val > bestGain {
						bestGain = val
					}
				}
			}
			L -= sz
		}

		// answering inquiries
		ans[qid] = bestGain + cnt1
		// restore left endpoint L
		L = (bid+1)*block_size - 1
		// restore bestGain
		bestGain = tmp_bestGain
		// restore subZeroBlocks
		head += cnt
		if tmp_firstValue != -1 {
			subZeroBlocks[head] = tmp_firstValue
		}
	}
	return ans
}