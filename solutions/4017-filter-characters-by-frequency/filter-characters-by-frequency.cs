public class Solution {
    public string FilterCharacters(string s, int k) {
        
        Dictionary<char, int> counter = new Dictionary<char, int>();

        // 1. Make frequency counter of s
        for(int i = 0; i < s.Length; i++) {
            char letter = s[i];
            counter[letter] = counter.GetValueOrDefault(letter, 0) + 1;
        }

        // 2. Construct the result
        StringBuilder result = new StringBuilder();

        for(int i = 0; i < s.Length; i++) {
            char letter = s[i];
            if(counter[letter] < k) {
                result.Append(letter);
            }
        }

        return result.ToString();
    }
}