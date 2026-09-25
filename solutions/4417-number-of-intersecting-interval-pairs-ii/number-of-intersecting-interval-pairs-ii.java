class Solution {
    public long countIntersectingIntervals(int[][] in) {
        int n = in.length;
        int st[] = new int[n], en[] = new int[n]; 
        for(int i = 0; i < n; i++) {
            st[i] = in[i][0]; 
            en[i] = in[i][1]; 
        }
        Arrays.sort(st); 
        Arrays.sort(en); 
        long ans = 0; 
        int idx = 0; 
        for(int i = 0; i < n; i++) {
            while(en[idx] < st[i]) {
                idx++; 
            }
            ans += i - idx; 
        }
        return ans; 
    }
}