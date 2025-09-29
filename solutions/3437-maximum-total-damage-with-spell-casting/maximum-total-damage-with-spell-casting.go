func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

type Pair struct {
	first  int
	second int64
}

func maximumTotalDamage(nums []int) int64 {
    sort.Ints(nums)
	var dp []Pair
	var preMax int64 = 0
	var ans int64 = 0
	dpIdx := 0

	for i := 0; i < len(nums); {
		for dpIdx < len(dp) && dp[dpIdx].first+2 < nums[i] {
			preMax = max(preMax, dp[dpIdx].second)
			dpIdx++
		}

		j := i
		var cur int64 = 0
		for j < len(nums) && nums[j] == nums[i] {
			cur += int64(nums[j])
			j++
		}

		ans = max(ans, cur+preMax)
		dp = append(dp, Pair{nums[i], cur + preMax})
		i = j
	}

	return ans
}