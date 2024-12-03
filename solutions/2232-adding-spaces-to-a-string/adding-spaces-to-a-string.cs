public class Solution {
    public string AddSpaces(string s, int[] spaces) {
        int i = 0, j = 0;
        StringBuilder res = new StringBuilder();
        
        while (i < s.Length && j < spaces.Length) {
            if (i < spaces[j]) {
                res.Append(s[i]);
                i++;
            } else {
                res.Append(' ');
                j++;
            }
        }
        
        if (i < s.Length) {
            res.Append(s.Substring(i));
        }
        
        return res.ToString();
    }
}