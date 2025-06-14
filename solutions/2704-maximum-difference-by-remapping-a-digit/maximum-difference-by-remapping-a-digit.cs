public class Solution {
    public int MinMaxDifference(int num) {
        string s = num.ToString();
        string t = s;
        int pos = 0;
        while (pos < s.Length && s[pos] == '9') {
            pos++;
        }
        if (pos < s.Length) {
            s = s.Replace(s[pos], '9');
        }
        t = t.Replace(t[0], '0');
        return int.Parse(s) - int.Parse(t);
    }
}