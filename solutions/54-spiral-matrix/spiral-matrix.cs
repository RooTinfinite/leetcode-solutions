public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        int VISITED = 101;
        int rows = matrix.Length, columns = matrix[0].Length;
        // Four directions that we will move: right, down, left, up.
        int[][] directions =
            new int [4][] { new int[] { 0, 1 }, new int[] { 1, 0 },
                            new int[] { 0, -1 }, new int[] { -1, 0 } };
        // Initial direction: moving right.
        int currentDirection = 0;
        // The number of times we change the direction.
        int changeDirection = 0;
        // Current place that we are at is (row, col).
        // row is the row index; col is the column index.
        int row = 0, col = 0;
        // Store the first element and mark it as visited.
        List<int> result = new List<int> { matrix[0][0] };
        matrix[0][0] = VISITED;
        while (changeDirection < 2) {
            while (0 <= row + directions[currentDirection][0] &&
                   row + directions[currentDirection][0] < rows &&
                   0 <= col + directions[currentDirection][1] &&
                   col + directions[currentDirection][1] < columns &&
                   matrix[row + directions[currentDirection][0]]
                         [col + directions[currentDirection][1]] != VISITED) {
                // Reset this to 0 since we did not break and change the
                // direction.
                changeDirection = 0;
                // Calculate the next place that we will move to.
                row += directions[currentDirection][0];
                col += directions[currentDirection][1];
                result.Add(matrix[row][col]);
                matrix[row][col] = VISITED;
            }

            // Change our direction.
            currentDirection = (currentDirection + 1) % 4;
            // Increment changeDirection because we changed our direction.
            changeDirection++;
        }

        return result;
    }
}