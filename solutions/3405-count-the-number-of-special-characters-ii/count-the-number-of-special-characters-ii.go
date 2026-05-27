func numberOfSpecialChars(word string) int {
	lastLow := [26]int{}
	firstUp := [26]int{}
	for i := range lastLow {
		lastLow[i] = -1
		firstUp[i] = -1
	}
	for i, c := range word {
		if c >= 'a' && c <= 'z' {
			lastLow[c-'a'] = i
		} else {
			if firstUp[c-'A'] == -1 {
				firstUp[c-'A'] = i
			}
		}
	}
	ans := 0
	for i := 0; i < 26; i++ {
		if lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i] {
			ans++
		}
	}
	return ans
}