func mapWordWeights(words []string, weights []int) string {
	ans := make([]byte, 0, len(words))
	for _, word := range words {
		s := 0
		for _, c := range word {
			s += weights[c-'a']
		}
		ans = append(ans, byte('z'-s%26))
	}
	return string(ans)
}