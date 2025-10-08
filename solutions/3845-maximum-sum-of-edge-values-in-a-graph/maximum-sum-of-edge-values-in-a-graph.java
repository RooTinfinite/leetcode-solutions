class Solution {
    public long maxScore(int n, int[][] edges) {
        long res = 1L* n*(n-1);
        int nc = n;
        while(n>2){
            res += 1L * n*(n-2);
            n--;
        }
        return nc == edges.length? res+= 2: res;
    }
}