class Solution {
    // Helper function to check if placing a queen at position (row,col) is safe
    private boolean isSafePlace(int n, char[][] nQueens, int row, int col) {
        // Check if there's any queen in the same column above current position
        for (int i = 0; i < n; i++) {
            if (nQueens[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal for any queen
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal for any queen
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }

        // If no conflicts found, position is safe
        return true;
    }

    // Recursive helper function to solve N-Queens problem
    private void solveNQueens(int n, List<List<String>> output, char[][] nQueens, int row) {
        // Base case: if we've placed queens in all rows, we found a valid solution
        if (row == n) {
            List<String> solution = new ArrayList<>();
            for (char[] rowArray : nQueens) {
                solution.add(new String(rowArray));
            }
            output.add(solution);
            return;
        }

        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++) {
            // If current position is safe
            if (isSafePlace(n, nQueens, row, col)) {
                // Place queen
                nQueens[row][col] = 'Q';
                // Recursively solve for next row
                solveNQueens(n, output, nQueens, row + 1);
                // Backtrack: remove queen for trying next position
                nQueens[row][col] = '.';
            }
        }
    }

    // Main function to solve N-Queens problem
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> output = new ArrayList<>();  // Stores all valid solutions
        char[][] nQueens = new char[n][n];  // Initialize empty board
        
        // Fill the board with dots
        for (int i = 0; i < n; i++) {
            Arrays.fill(nQueens[i], '.');
        }
        
        solveNQueens(n, output, nQueens, 0); // Start solving from row 0
        return output;
    }
}