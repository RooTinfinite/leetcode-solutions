import java.util.HashSet;
import java.util.Set;

class Solution {
    public int centeredSubarrays(int[] nums) {
        int a = 0, b = nums.length;
        int[] c = nums;
        for (int d = 0; d < b; ++d) {
            int e = 0;
            Set<Integer> f = new HashSet<>();
            for (int g = d; g < b; ++g) {
                e += c[g];
                f.add(c[g]);
                if (f.contains(e)) a++;
            }
        }
        return a;
    }
}