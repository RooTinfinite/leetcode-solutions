public class Solution {
    public string ProcessStr(string s) {
        var result = new StringBuilder();
        foreach (var ch in s) {
            if (ch == '*') {
                if (result.Length > 0)
                    result.Length--;
            } else if (ch == '#') {
                result.Append(result.ToString());
            } else if (ch == '%') {
                var arr = result.ToString().ToCharArray();
                Array.Reverse(arr);
                result = new StringBuilder(new string(arr));
            } else {
                result.Append(ch);
            }
        }
        return result.ToString();
    }
}