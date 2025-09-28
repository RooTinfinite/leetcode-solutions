class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });

        int ans = 0;
        int covered = points[0][0];
        for (int i = 0; i < points.length; i++) {
            if (covered + w < points[i][0]) {
                covered = points[i][0];
                ans++;
            }
        }

        return ans + 1;
    }
}