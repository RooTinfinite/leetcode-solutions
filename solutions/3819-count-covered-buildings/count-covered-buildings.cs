public class Solution {
    public int CountCoveredBuildings(int n, int[][] buildings) {
        int[] maxRow = new int[n + 1];
        int[] minRow = new int[n + 1];
        int[] maxCol = new int[n + 1];
        int[] minCol = new int[n + 1];

        Array.Fill(minRow, n + 1);
        Array.Fill(minCol, n + 1);
        foreach (var p in buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = Math.Max(maxRow[y], x);
            minRow[y] = Math.Min(minRow[y], x);
            maxCol[x] = Math.Max(maxCol[x], y);
            minCol[x] = Math.Min(minCol[x], y);
        }

        int res = 0;
        foreach (var p in buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
                y < maxCol[x]) {
                res++;
            }
        }

        return res;
    }
}