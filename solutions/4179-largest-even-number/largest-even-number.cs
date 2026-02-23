public class Solution {
    public string LargestEven(string s) {
        int ind = -1;

        for (int i = s.Length - 1; i >= 0; i--) {
            if (s[i] == '2') {
                ind = i;
                break;
            }
        }

        return s.Substring(0, ind + 1);
    }
}