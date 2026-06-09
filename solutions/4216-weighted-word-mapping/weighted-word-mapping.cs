public class Solution {
    public string MapWordWeights(string[] words, int[] weights) {
        var ans = new StringBuilder(words.Length);
        foreach (string word in words) {
            int s = 0;
            foreach (char c in word) {
                s += weights[c - 'a'];
            }
            ans.Append((char)('z' - s % 26));
        }
        return ans.ToString();
    }
}