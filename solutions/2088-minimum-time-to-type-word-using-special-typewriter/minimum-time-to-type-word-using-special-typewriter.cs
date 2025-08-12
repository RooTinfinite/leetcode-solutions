public class Solution {
    public int MinTimeToType(string word) {
        int ans = word.Length;
        int cur = 1;
        foreach (char c in word) {
            int pos = c - 96;
            int diff = Math.Abs(pos - cur);
            ans += Math.Min(diff, 26 - diff);
            cur = pos;
        }
        return ans;
    }
}