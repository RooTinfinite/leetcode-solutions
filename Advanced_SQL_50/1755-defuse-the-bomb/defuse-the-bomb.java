class Solution {
    public int[] decrypt(int[] code, int k) {
        int N = code.length;
        int[] res = new int[N];
        
        if (k == 0) {
            return res;
        }
        
        int l = 0;
        int curSum = 0;
        
        for (int r = 0; r < N + Math.abs(k); r++) {
            curSum += code[r % N];
            
            if (r - l + 1 > Math.abs(k)) {
                curSum -= code[l % N];
                l = (l + 1) % N;
            }
            
            if (r - l + 1 == Math.abs(k)) {
                if (k > 0) {
                    res[(l - 1 + N) % N] = curSum;
                } else {
                    res[(r + 1) % N] = curSum;
                }
            }
        }
        
        return res;
    }
}