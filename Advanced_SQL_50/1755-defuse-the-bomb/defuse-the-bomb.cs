public class Solution {
    public int[] Decrypt(int[] code, int k) {
        int N = code.Length;
        int[] res = new int[N];
        
        for (int i = 0; i < N; i++) {
            if (k > 0) {
                for (int j = i + 1; j < i + 1 + k; j++) {
                    res[i] += code[j % N];
                }
            } else if (k < 0) {
                for (int j = i - 1; j > i - 1 - Math.Abs(k); j--) {
                    res[i] += code[((j % N) + N) % N];
                }
            }
        }
        
        return res;
    }
}