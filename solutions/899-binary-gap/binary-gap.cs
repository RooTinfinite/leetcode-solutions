public class Solution {
    public int BinaryGap(int n) {
                   var last = -1;
           var result = 0;
           for (int i = 0; i < 32; i++)
           {
               if (((n >> i) & 1) == 1)
               {
                   if (last >= 0)
                       result = Math.Max(result, i - last);
                   last = i;
               }
           }

           return result;
    }
}