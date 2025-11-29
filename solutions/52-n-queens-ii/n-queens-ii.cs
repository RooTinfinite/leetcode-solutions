public class Solution {
    private int size;

    public int TotalNQueens(int n) {
        size = n;
        return Backtrack(0, new HashSet<int>(), new HashSet<int>(),
                         new HashSet<int>());
    }

    private int Backtrack(int row, HashSet<int> diagonals,
                          HashSet<int> antiDiagonals, HashSet<int> cols) {
        // Base case - N queens have been placed
        if (row == size) {
            return 1;
        }

        int solutions = 0;
        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.Contains(col) || diagonals.Contains(currDiagonal) ||
                antiDiagonals.Contains(currAntiDiagonal)) {
                continue;
            }

            // "Add" the queen to the board
            cols.Add(col);
            diagonals.Add(currDiagonal);
            antiDiagonals.Add(currAntiDiagonal);
            // Move on to the next row with the updated board state
            solutions += Backtrack(row + 1, diagonals, antiDiagonals, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.Remove(col);
            diagonals.Remove(currDiagonal);
            antiDiagonals.Remove(currAntiDiagonal);
        }

        return solutions;
    }
}