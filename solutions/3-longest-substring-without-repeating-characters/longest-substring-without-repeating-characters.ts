function lengthOfLongestSubstring(s: string): number {
    const chars: (number | null)[] = Array(128).fill(null);
    let left = 0;
    let right = 0;
    let res = 0;
    while (right < s.length) {
        const r = s.charCodeAt(right);
        const index = chars[r];
        if (index !== null && index >= left && index < right) {
            left = index + 1;
        }
        res = Math.max(res, right - left + 1);
        chars[r] = right;
        right++;
    }
    return res;
}