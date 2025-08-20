public class Solution {
   readonly string target = "RGB";

     public int CountPoints(string rings)
     {
         int count = 0;
         foreach (var item in GetDictionary(rings))
         {
             if (CheckingListChars(item.Value, target))
                 count++;
         }
         return count;
     }

     static bool CheckingListChars(List<char> chars, string target) =>
         target.All(c => chars.Contains(c));

     static Dictionary<int, List<char>> GetDictionary(string rings)
     {
         var dict = new Dictionary<int, List<char>>();
         for (int i = 0; i <= 9; i++)
             dict[i] = new List<char>();

         for (int i = 0; i < rings.Length; i += 2)
         {
             char color = rings[i];
             int index = rings[i + 1] - '0';
             dict[index].Add(color);
         }
         return dict;
     }
}