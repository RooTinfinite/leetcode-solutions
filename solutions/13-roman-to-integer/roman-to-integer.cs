public class Solution {
    private static int CalcScale(char c, char a1, char a2) {
        return (c == a1 || c == a2) ? -1 : 1;
    }
    
    public int RomanToInt(string s) {
        int result = 0;
        
        for (int n = 0; n < s.Length; n++) {
            char nextChar = (n + 1 < s.Length) ? s[n + 1] : '\0';
            
            switch (s[n]) {
                case 'M': result += 1000; break;
                case 'D': result += 500; break;
                case 'C': result += 100 * CalcScale(nextChar, 'M', 'D'); break;
                case 'L': result += 50; break;
                case 'X': result += 10 * CalcScale(nextChar, 'C', 'L'); break;
                case 'V': result += 5; break;
                case 'I': result += 1 * CalcScale(nextChar, 'X', 'V'); break;
            }
        }
        return result;
    }
}