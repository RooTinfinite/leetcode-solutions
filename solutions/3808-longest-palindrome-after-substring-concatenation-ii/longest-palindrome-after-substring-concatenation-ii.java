import java.util.*;

class Solution {
    public int longestPalindrome(String s, String t) {
        String tReversed = new StringBuilder(t).reverse().toString();

        List<int[]> sameSections = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            int k = i;
            for (int j = 0; j < tReversed.length(); j++) {
                if (k < s.length() && tReversed.charAt(j) == s.charAt(k)) k++;
                else {
                    if (k > i) sameSections.add(new int[]{i, j - (k - i), k - i});
                    k = i;
                    if (tReversed.charAt(j) == s.charAt(k)) k++;
                }
            }
            if (k > i) sameSections.add(new int[]{i, tReversed.length() - (k - i), k - i});
        }

        boolean[][] dpS = new boolean[s.length()][s.length()];
        boolean[][] dpT = new boolean[tReversed.length()][tReversed.length()];
        fillPalindromeDp(dpS, s);
        fillPalindromeDp(dpT, tReversed);
        int[] longestPalS = new int[s.length()];
        int[] longestPalT = new int[tReversed.length()];

        for (int i = 0; i < dpS.length; i++) {
            if (dpS[i][dpS.length - 1]) longestPalS[i] = dpS.length - i;
            else {
                for (int j = i; j < dpS.length; j++) {
                    if (dpS[i][j]) {
                        longestPalS[i] = j - i + 1;
                    }
                }
            }
        }

        for (int i = 0; i < dpT.length; i++) {
            if (dpT[i][dpT.length - 1]) longestPalT[i] = dpT.length - i;
            else {
                for (int j = i; j < dpT.length; j++) {
                    if (dpT[i][j]) {
                        longestPalT[i] = j - i + 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int[] section : sameSections) {
            int start1 = section[0];
            int start2 = section[1];
            int len = section[2];

            int lenPalAfterS = start1 + len >= longestPalS.length ? 0 : longestPalS[start1 + len];
            int lenPalAfterT = start2 + len >= longestPalT.length ? 0 : longestPalT[start2 + len];

            ans = Math.max(ans, Math.max(lenPalAfterS, lenPalAfterT) + len * 2);
        }

        for (int i = 0; i < longestPalS.length; i++) ans = Math.max(ans, longestPalS[i]);
        for (int i = 0; i < longestPalT.length; i++) ans = Math.max(ans, longestPalT[i]);

        return ans;
    }

    void fillPalindromeDp(boolean[][] dp, String s) {
        for (int i = 0; i < s.length(); i++) dp[i][i] = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) dp[i][i + 1] = true;
        }

        for (int diff = 2; diff < s.length(); diff++) {
            for (int i = 0; i + diff < s.length(); i++) {
                if (s.charAt(i) == s.charAt(i + diff) && dp[i + 1][i + diff - 1]) {
                    dp[i][i + diff] = true;
                }
            }
        }
    }
}