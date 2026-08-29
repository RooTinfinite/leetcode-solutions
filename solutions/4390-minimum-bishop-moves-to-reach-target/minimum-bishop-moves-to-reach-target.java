class Solution {

    public int minBishopMoves(int[] x, int[] y) {

        if (Math.abs(x[0] - y[0]) == Math.abs(y[1] - x[1])) {
            return 1;
        }

        if ((x[0] + x[1]) % 2 == (y[0] + y[1]) % 2) {
            return 2;
        }

        return -1;
    }
}