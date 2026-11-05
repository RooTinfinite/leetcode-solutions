func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	cnt := 0
	for _, x := range arr1 {
		ok := true
		for _, y := range arr2 {
			ok = ok && abs(x-y) > d
		}
		if ok {
			cnt++
		}
	}
	return cnt
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}