class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, int[]> yRangeGivenX = new HashMap<>();
        Map<Integer, int[]> xRangeGivenY = new HashMap<>();
        
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            yRangeGivenX.putIfAbsent(x, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});
            yRangeGivenX.get(x)[0] = Math.min(yRangeGivenX.get(x)[0], y);
            yRangeGivenX.get(x)[1] = Math.max(yRangeGivenX.get(x)[1], y);

            xRangeGivenY.putIfAbsent(y, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});
            xRangeGivenY.get(y)[0] = Math.min(xRangeGivenY.get(y)[0], x);
            xRangeGivenY.get(y)[1] = Math.max(xRangeGivenY.get(y)[1], x);
        }
        
        int count = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            if (xRangeGivenY.get(y)[0] < x && x < xRangeGivenY.get(y)[1] &&
                yRangeGivenX.get(x)[0] < y && y < yRangeGivenX.get(x)[1]) {
                count++;
            }
        }
        
        return count;
    }
}