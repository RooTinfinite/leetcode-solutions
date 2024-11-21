public class Solution {
    public int FirstUniqChar(string inputStr) {
        int firstUnique = int.MaxValue;
        
        for (char c = 'a'; c <= 'z'; c++) {
            if (inputStr.Contains(c)) {
                if (inputStr.IndexOf(c) == inputStr.LastIndexOf(c)) {
                    firstUnique = Math.Min(firstUnique, inputStr.IndexOf(c));
                }
            }
        }
        
        return firstUnique != int.MaxValue ? firstUnique : -1;
    }
}