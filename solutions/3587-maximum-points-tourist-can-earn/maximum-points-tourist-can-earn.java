public class Solution {
    public int maxScore(int n, int k, int[][] stayScore, int[][] travelScore) {
        int[] curr = new int[n];
        int[] prev = new int[n];

        for (int day = k - 1; day >= 0; day--) {
            for (int city = 0; city < n; city++) {
                int move = 0;
                for (int i = 0; i < n; i++) {
                    move = Math.max(move, prev[i] + travelScore[city][i]);}

                int stay = Math.max(curr[city], prev[city] + stayScore[day][city]);
                curr[city] = Math.max(move, stay);}

            int[] temp = prev;
            prev = curr;
            curr = temp;}

        int maxScore = 0;
        for (int score : prev) {
            maxScore = Math.max(maxScore, score);}

        return maxScore;}
}