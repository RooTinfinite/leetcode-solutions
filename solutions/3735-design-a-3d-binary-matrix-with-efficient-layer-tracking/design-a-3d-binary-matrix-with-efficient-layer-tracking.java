public class Matrix3D {

    private final int[][][] matrix;
    private final int[] countOnesForLayerX;

    public Matrix3D(int size) {
        matrix = new int[size][size][size];
        countOnesForLayerX = new int[size];
    }

    public void setCell(int x, int y, int z) {
        countOnesForLayerX[x] += matrix[x][y][z] ^ 1;
        matrix[x][y][z] = 1;
    }

    public void unsetCell(int x, int y, int z) {
        countOnesForLayerX[x] -= matrix[x][y][z] & 1;
        matrix[x][y][z] = 0;
    }

    public int largestMatrix() {
        int maxOnesForLayerX = 0;
        int largestLayerX = countOnesForLayerX.length - 1;
        for (int i = countOnesForLayerX.length - 1; i >= 0; --i) {
            if (maxOnesForLayerX < countOnesForLayerX[i]) {
                maxOnesForLayerX = countOnesForLayerX[i];
                largestLayerX = i;
            }
        }
        return largestLayerX;
    }
}