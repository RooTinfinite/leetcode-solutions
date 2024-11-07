public class Solution {
    public int LargestCombination(int[] candidates) {
        int[] ans = new int[32];
        
        foreach(int x in candidates) {
            Find(x, ans);
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = Math.Max(res, ans[i]);
        }
        
        return res;
    }
    
    private void Find(int n, int[] ans) {
        int j = 31;
        
        while(n > 0) {
            int a = (n & 1);
            ans[j] += a;
            n >>= 1;
            j--;
        }
    }
}