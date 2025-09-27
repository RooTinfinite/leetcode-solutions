function maximumLengthSubstring(s: string): number {
    let ans = 0, ii = 0; 
    const freq = new Map(); 
    for (const [i, ch] of s.split('').entries()) {
        freq.set(ch, 1 + (freq.get(ch) ?? 0)); 
        while (freq.get(ch) == 3) {
            freq.set(s[ii], freq.get(s[ii])-1); 
            ++ii; 
        }
        ans = Math.max(ans, i-ii+1); 
    }
    return ans; 
};