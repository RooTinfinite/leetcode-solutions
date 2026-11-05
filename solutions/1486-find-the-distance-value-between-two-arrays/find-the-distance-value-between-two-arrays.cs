public class Solution {
    public int FindTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int cnt = 0;
        foreach (int x in arr1) {
            bool ok = true;
            foreach (int y in arr2) {
                ok &= Math.Abs(x - y) > d;
            }
            cnt += ok ? 1 : 0;
        }
        return cnt;
    }
}