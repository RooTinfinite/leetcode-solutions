public class Solution {
    public int FirstUniqChar(string s) {
        Dictionary<char, int> count = new Dictionary<char, int>();
        
        foreach (char c in s) {
            if (!count.ContainsKey(c)) {
                count[c] = 0;
            }
            count[c]++;
        }
        
        for (int i = 0; i < s.Length; i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
}