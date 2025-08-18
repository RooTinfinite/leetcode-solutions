public class Solution {
    public int CountVowelSubstrings(string word) {
        HashSet<char> vowels = new HashSet<char>{'a', 'e', 'i', 'o', 'u'};
        int res = 0;
          int n = word.Length;

        for(int i =0; i < n;i++){
             HashSet<char> seen = new HashSet<char>();

             for(int j = i; j < n;j++){
                char c  = word[j];

                if(!vowels.Contains(c)) break;
                
                seen.Add(c);

                  if(seen.Count == 5) res++;
             }
        }
  return res;

    }
}