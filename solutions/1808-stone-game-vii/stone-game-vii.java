class Solution {
    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        int [] prefix = new int[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
        int [][] dp = new int[n][n];
        for(int IntervalSteps = 2; IntervalSteps <= n; IntervalSteps++){
            for(int LeftPointer = 0; LeftPointer  <= n - IntervalSteps; LeftPointer++){
                int RightPointer = LeftPointer + IntervalSteps - 1;
                    int removeMostLeftItem = prefix[RightPointer + 1] - prefix[LeftPointer + 1] - dp[LeftPointer + 1][RightPointer];
                    int removeMostRightItem = prefix[RightPointer] - prefix[LeftPointer] - dp[LeftPointer][RightPointer - 1 ];
                    dp[LeftPointer][RightPointer] = Math.max(removeMostLeftItem , removeMostRightItem);
            }
        }
        return dp[0][n - 1];
    }
}