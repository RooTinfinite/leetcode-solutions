class Solution {
    private int[][] getCount(String s) {
        int n = s.length();
        int[][] dist = new int[n][27];

        int[] prev = new int[n];
        int[] curr = new int[n];

        for (int i = 1; i <= 26; i++) {
            int[] freq = new int[26];
            int left = 0, distinct = 0;

            for (int right = 0; right < n; right++) {
                int c = s.charAt(right) - 'a';

                if (freq[c]++ == 0)
                    distinct++;

                while (distinct > i) {
                    int x = s.charAt(left++) - 'a';

                    if (--freq[x] == 0)
                        distinct--;
                }

                curr[right] = right - left + 1;
                dist[right][i] = curr[right] - prev[right];
            }

            int[] temp = prev;
            prev = curr;
            curr = temp;
        }

        return dist;
    }

    public long countMagicalPairs(String s) {
        int n = s.length();
        int[][] left = getCount(s);

        String reversed =
            new StringBuilder(s).reverse().toString();
        int[][] rev = getCount(reversed);

        long ans = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int d = 1; d <= 26; d++) {
                int lftCnt = left[i][d];
                int rtCnt = rev[n - 2 - i][d];

                ans += (long) lftCnt * rtCnt;
            }
        }

        return ans;
    }
}