func findKthSmallest(coins []int, k int) int64 {
	sort.Ints(coins)
	newCoins := make([]int, 0)
	for _, x := range coins {
		flag := true
		for _, y := range newCoins {
			if x%y == 0 {
				flag = false
				break
			}
		}
		if flag {
			newCoins = append(newCoins, x)
		}
	}
	coins = newCoins

	n := len(coins)
	m := 1 << n
	lcm := make([]int64, m)
	l := int64(k)
	r := int64(coins[0])*int64(k) + 1

	lcm[0] = 1
	for mask := 1; mask < m; mask++ {
		preMask := mask & (mask - 1)
		i := bits.TrailingZeros(uint(mask))

		tmp := lcm[preMask] / gcd(lcm[preMask], int64(coins[i]))
		if tmp <= r/int64(coins[i]) {
			lcm[mask] = tmp * int64(coins[i])
		} else {
			lcm[mask] = r + 1
		}
	}

	count := func(x int64) int64 {
		var res int64 = 0
		for mask := 1; mask < m; mask++ {
			if lcm[mask] > x {
				continue
			}
			if bits.OnesCount(uint(mask))&1 == 1 {
				res += x / lcm[mask]
			} else {
				res -= x / lcm[mask]
			}
		}
		return res
	}

	for l < r {
		x := l + (r-l)/2
		if count(x) >= int64(k) {
			r = x
		} else {
			l = x + 1
		}
	}
	return l
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}