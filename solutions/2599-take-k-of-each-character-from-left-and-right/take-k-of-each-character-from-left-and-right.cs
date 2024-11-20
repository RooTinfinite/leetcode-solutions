public class Solution {
    public int TakeCharacters(string s, int k) {
        // Total counts
        int[] count = new int[3];
        foreach (char c in s) {
            count[c - 'a']++;
        }
        
        if (Math.Min(Math.Min(count[0], count[1]), count[2]) < k) {
            return -1;
        }
        
        // Sliding Window
        int res = int.MaxValue;
        int l = 0;
        for (int r = 0; r < s.Length; r++) {
            count[s[r] - 'a']--;
            
            while (Math.Min(Math.Min(count[0], count[1]), count[2]) < k) {
                count[s[l] - 'a']++;
                l++;
            }
            res = Math.Min(res, s.Length - (r - l + 1));
        }
        return res;
    }
}
