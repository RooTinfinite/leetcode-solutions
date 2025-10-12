class Solution {
    static public int minOperations(String word1, String word2) {
        char[] arr1 = word1.toCharArray();
        char[] arr2 = word2.toCharArray();
        int n = arr1.length;
        Integer[][] dp = new Integer[n][n];
        int ans = solve(0, 0, arr1, arr2, n, dp);
        return ans;
    }

    static int solve(int i, int j, char[] arr1, char[] arr2, int n, Integer[][] dp) {
        if (i >= n) return 0;
        if (j >= n) return 100000;

        if (dp[i][j] != null) return dp[i][j];

        int startSubstr = 0, dontStartSubstr = 0;
        dontStartSubstr = solve(i, j + 1, arr1, arr2, n, dp);
        startSubstr = Math.min(mininumOpr(arr1, arr2, i, j, false), mininumOpr(arr1, arr2, i, j, true)) + solve(j + 1, j + 1, arr1, arr2, n, dp);
        return dp[i][j] = Math.min(startSubstr, dontStartSubstr);
    }

    static int mininumOpr(char[] arr1, char[] arr2, int i, int j, boolean isReversed) {
        int operations = (isReversed ? 1 : 0), x = i, y = 0, n = arr1.length, idx = (isReversed ? j : i), mul = (isReversed ? -1 : 1);
        int[][] freqOfMismatched = new int[26][26];
        for (int k = i; k <= j; k++) {
            if (arr1[x] != arr2[idx]) {
                char wanted = arr1[x], got = arr2[idx];
                if (freqOfMismatched[got - 'a'][wanted - 'a'] > 0) {
                    freqOfMismatched[got - 'a'][wanted - 'a']--;
                } else {
                    freqOfMismatched[wanted - 'a'][got - 'a']++;
                    operations++;
                }
            }
            x++;
            idx = idx + 1 * mul;
        }
        return operations;
    }

}