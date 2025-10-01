public class Solution {
    int helper(String source, String pattern, int[] arr, int i, int j, int[][] dp) {
        if(j == pattern.length()) return 0;
        if(i == source.length()) return Integer.MAX_VALUE;
        if(dp[i][j] != -1) return dp[i][j];
        int min = helper(source, pattern, arr, i + 1, j, dp);
        if(source.charAt(i) == pattern.charAt(j)) {
            int take = helper(source, pattern, arr, i + 1, j + 1, dp);
            if(take != Integer.MAX_VALUE) min = Math.min(min, take + arr[i]);
        }
        dp[i][j] = min;
        return min;
    }
    public int maxRemovals(String source, String pattern, int[] targetIndices) {
        int[] arr = new int[source.length()];
        for(int i : targetIndices) arr[i] = 1;
        int[][] dp = new int[source.length()][pattern.length()];
        for(int[] row : dp) Arrays.fill(row, -1);
        return targetIndices.length - helper(source, pattern, arr, 0, 0, dp);
    }
}