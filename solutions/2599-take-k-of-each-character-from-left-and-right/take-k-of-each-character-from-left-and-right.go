func takeCharacters(s string, k int) int {
    freq := make([]int, 3)
    n := len(s)
    
    for _, c := range s {
        freq[c-'a']++
    }
    
    if freq[0] < k || freq[1] < k || freq[2] < k {
        return -1
    }
    
    curr := make([]int, 3)
    maxLen := 0
    left := 0
    
    for right := 0; right < n; right++ {
        curr[s[right]-'a']++
        
        for left <= right && (curr[0] > freq[0]-k || 
            curr[1] > freq[1]-k || 
            curr[2] > freq[2]-k) {
            curr[s[left]-'a']--
            left++
        }
        
        if right-left+1 > maxLen {
            maxLen = right-left+1
        }
    }
    
    return n - maxLen
}