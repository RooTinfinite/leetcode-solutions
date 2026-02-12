class Solution {
    Long dp[][][][][];
    public long countBalanced(long low, long high) {
        return solve(high) - solve(low - 1);
    }

    public long solve(long num){
        dp = new Long[17][2][2][150][150];
        return helper(String.valueOf(num), 0, 1, 1, 0, 0);
    }

    public long helper(String str, int idx, int tight, int startZero, int sumOdd, int sumEven){
        if(idx >= str.length()) return (sumOdd == sumEven)? 1 : 0;
        if(dp[idx][tight][startZero][sumOdd][sumEven] != null) return dp[idx][tight][startZero][sumOdd][sumEven];
        
        int lb = 0;
        int ub = (tight == 1)? (int) (str.charAt(idx) - '0') : 9;

        long count = 0L;
        for(int i = lb; i <= ub; i++){
            if(i == 0 && startZero == 1){
                count += helper(str, idx + 1, 0, startZero, sumOdd, sumEven);
            } else {
                count += helper(str, idx + 1, (tight == 1 && i == ub)? 1 : 0, 0, (idx % 2 != 0)? sumOdd + i : sumOdd, (idx % 2 == 0)? sumEven + i : sumEven);
            }
        }
        return dp[idx][tight][startZero][sumOdd][sumEven] = count;
    }
}