func distinctSubseqII(s string) int {
	const MOD int64 = 1000000007

	var dp int64 = 1
	last := make([]int64, 26)

	for i := 0; i < len(s); i++ {
		index := int(s[i] - 'a')

		oldDp := dp

		dp = (2*dp - last[index] + MOD) % MOD

		last[index] = oldDp
	}

	return int((dp - 1 + MOD) % MOD)
}