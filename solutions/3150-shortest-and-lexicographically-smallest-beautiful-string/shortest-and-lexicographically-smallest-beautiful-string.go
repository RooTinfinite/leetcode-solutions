func shortestBeautifulSubstring(s string, k int) string {
	for m := k; m <= len(s); m++ {
		ans := ""
		for i := m; i <= len(s); i++ {
			t := s[i-m : i]
			if (ans == "" || t < ans) && strings.Count(t, "1") == k {
				ans = t
			}
		}
		if ans != "" {
			return ans
		}
	}
	return ""
}