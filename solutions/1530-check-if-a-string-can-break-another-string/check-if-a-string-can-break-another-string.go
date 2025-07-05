func checkIfCanBreak(s1 string, s2 string) bool {
	var a, b [26]int
	for _, v := range s1 {
		a[v-'a']++
	}
	for _, v := range s2 {
		b[v-'a']++
	}
	ans := true
	var i, j, cnt1, cnt2 int
	for i < 26 && j < 26 {
		if a[i] == cnt1 {
			i++
			cnt1 = 0
			continue
		}
		if b[j] == cnt2 {
			j++
			cnt2 = 0
			continue
		}
		cnt1++
		cnt2++
		if i > j {
			ans = false
			break
		}
	}
	if ans {
		return true
	}
	i = 0
	j = 0
	cnt1 = 0
	cnt2 = 0
	ans = true
	for i < 26 && j < 26 {
		if a[i] == cnt1 {
			i++
			cnt1 = 0
			continue
		}
		if b[j] == cnt2 {
			j++
			cnt2 = 0
			continue
		}
		cnt1++
		cnt2++
		if i < j {
			ans = false
			break
		}
	}
	return ans 
	
}