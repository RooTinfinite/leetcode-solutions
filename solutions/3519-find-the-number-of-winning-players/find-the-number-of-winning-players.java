class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int res = 0;
        int[][] players = new int[n][11];
        boolean[] seen = new boolean[n];
        for (int[] p : pick){
            if (++players[p[0]][p[1]] > p[0] && !seen[p[0]]){
                res++;
                seen[p[0]] = true;
            }
        }
        return res;
    }
}