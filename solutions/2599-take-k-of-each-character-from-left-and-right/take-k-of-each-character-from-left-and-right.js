// JavaScript

var takeCharacters = function(s, k) {
    const freq = [0, 0, 0];
    const n = s.length;
    
    for (const c of s) {
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    
    if (freq[0] < k || freq[1] < k || freq[2] < k) {
        return -1;
    }
    
    const curr = [0, 0, 0];
    let maxLen = 0;
    let left = 0;
    
    for (let right = 0; right < n; right++) {
        curr[s.charCodeAt(right) - 'a'.charCodeAt(0)]++;
        
        while (left <= right && (curr[0] > freq[0] - k ||
               curr[1] > freq[1] - k ||
               curr[2] > freq[2] - k)) {
            curr[s.charCodeAt(left) - 'a'.charCodeAt(0)]--;
            left++;
        }
        
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    return n - maxLen;
};