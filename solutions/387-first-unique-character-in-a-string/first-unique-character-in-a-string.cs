public class Solution {
    public int FirstUniqChar(string s) {
        List<int> firstUnique = new List<int>();
        string letters = "abcdefghijklmnopqrstuvwxyz";
        
        foreach (char letter in letters) {
            if (s.Count(c => c == letter) == 1) {
                firstUnique.Add(s.IndexOf(letter));
            }
        }
        
        return firstUnique.Count > 0 ? firstUnique.Min() : -1;
    }
}