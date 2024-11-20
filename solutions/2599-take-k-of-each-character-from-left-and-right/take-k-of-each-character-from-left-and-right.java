class Solution {
    public int takeCharacters(String s, int k) {
        int[] freq = new int[3];
        int n = s.length();
        
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        if (freq[0] < k || freq[1] < k || freq[2] < k) {
            return -1;
        }
        
        int[] curr = new int[3];
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            curr[s.charAt(right) - 'a']++;
            
            while (left <= right && (curr[0] > freq[0] - k || 
                   curr[1] > freq[1] - k || 
                   curr[2] > freq[2] - k)) {
                curr[s.charAt(left) - 'a']--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return n - maxLen;
    }
}
