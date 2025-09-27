class Solution {
    public int maximumLengthSubstring(String s) {
        int ans = 0; 
        int[] freq = new int[26]; 
        for (int i = 0, ii = 0; i < s.length(); ++i) {
            ++freq[s.charAt(i)-97]; 
            while (freq[s.charAt(i)-97] == 3) --freq[s.charAt(ii++)-97]; 
            ans = Math.max(ans, i-ii+1); 
        }
        return ans; 
    }
}